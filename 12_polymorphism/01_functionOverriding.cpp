#include <iostream>

using namespace std;

// classes
class Parent {
    public:
    void display() {
        cout<<"Display of parent class"<<endl;
    };

    void fun() {
        cout<<"fun of parent"<<endl;
    };
};

class Child:public Parent {
    //  if we write same function in child then it overwrites the parent display function
    public:
    void display() {
        cout<<"Display of child class"<<endl;
    };

    // if no of parameters are different in BAse and child functions
    void fun(int x) {
        cout<<"fun of child"<<endl;
    };
};

int main() {
    Parent p;
    p.display();

    Child c;
    c.display();

    // fun of child requires int x to execute if we don't pass any parameter then it won't call base fun as expected rather it trows error to deal with this use
    c.fun(1); // calls child fun
    
    // c.fun(); //error
    c.Parent::fun();

    return 0;
};
// can a function access all the members of class ie public, protected and private

#include <iostream>

using namespace std;

class Test {
    private:
    int a;

    protected:
    int b;

    public:
    int c;

    // make fun a friend
    friend void fun();
};

class Your; // Your class declaration note==> do not use curly brace to avoid inalid assignment

class My {
    private:
    int a=10;
    // to access private variable in another class we need to declare it as friend
    friend Your;
};

class Your {
    public:
    My m;
    
    // see fun can access private variables of My due to friend attribute
    void fun() {
        cout<<m.a<<endl;
    };
};

// fun can access all member of class test
void fun() {
    Test t;
    t.a=15;
    t.b=20;
    t.c=30;
};

int main() {

    return 0;
};
#include <iostream>

using namespace std;

class Base {
    public:
    Base() {
        cout<<"Default constructor of Base class"<<endl;
    };

    Base(int x) {
        cout<<"Parameterize constructor of Base class "<<x<<endl;
    };
};

class Derived:public Base {
    public:
    Derived() {
        cout<<"Default constructor of Derived class"<<endl;
    };

    Derived(int x) {
        cout<<"Parameterize constructor of Derived class "<<x<<endl;
    };

    // to call parameterise construcotr of base class x is sent to base and a is used ere only
    Derived(int x, int a):Base(x) {
        cout<<"Parameterize constructor of Derived class "<<a<<endl;
    };
};

int main() {
    // first parent class constructor will be called then child class one shall be called
    // here default constructor of base class and default constructor of derived class are executed
    Derived d1;
    // here default constructor of base classs but parameterise constructor of derived class is executed
    Derived d2(5);

    // to call parameterise constructor of base class with parameterise constructor of serived class use the new 2 parameter constructor made above
    Derived d3(10,20); // 10==> sent to Base class and 20==> used in derived class


    return 0;
};

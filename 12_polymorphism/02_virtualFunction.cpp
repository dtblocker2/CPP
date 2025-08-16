#include <iostream>

using namespace std;

// classes
class Base {
    public:
    // to run derived class function use virtual function
    void fun() {
        cout<<"fun of base"<<endl;
    };

    virtual void fun2() {
        cout<<"fun2 of base"<<endl;
    };
};

class Derived:public Base {
    public:
    void fun() {
        cout<<"fun of derived"<<endl;
    };

    void fun2() {
        cout<<"fun2 of derived"<<endl;
    };
};

int main() {
    // base class pointer to derived class object call which function ie original function in base or overwriten in derived class
    Base *p = new Derived();

    // by default it calls base function
    // and not overwritten one if virtual keyword is not used
    p->fun();
    p->fun2();

    /* using virtual function and overriding we can achieve polymorphism */
    return 0;
};
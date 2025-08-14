#include <iostream>

using namespace std;

class Base {
    private:
    int a;

    protected:
    int b;

    public:
    int c;

    void funBase() {
        a=10;
        b=20;
        c=30;
    };
};

class Derived:public Base{
    public:
    void funDerived() {
        // derived class can not access private variales
        // a=1;

        // derived classes can access protected and public variables
        b=2;
        c=3;
    };
};

int main() {
    Base x;
    // can't access private member
    // x.a=11;
    // can't access protected member
    // x.b=22;
    // can access public member
    x.c=33;

    Derived y;
    // can't access protected member
    // y.b=100;
    // can access public member
    y.c=44;

    return 0;
};

/* 
which type of access specifiers are accessible to which operation
            private     protected       public

inside      yes         yes             yes
class

inside      no          yes             yes
derived
class

on object   no          no              yes

*/

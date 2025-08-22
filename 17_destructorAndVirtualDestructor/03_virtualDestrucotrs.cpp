#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }

    // Trying to overload destructor (not allowed)
    // ~Base(int x) { } // Uncommenting this will cause compilation error
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called" << endl;
    }

    ~Derived() override { // Override base destructor
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    Base* obj = new Derived(); // Base pointer to Derived object
    delete obj; // Properly calls Derived and Base destructors due to virtual ~Base()

    // Demonstrate destructors cannot be overloaded - uncommenting below causes compilation error
    /*
    class Test {
    public:
        ~Test() {}
        ~Test(int x) {} // Error: destructor cannot be overloaded
    };
    */

    return 0;
}

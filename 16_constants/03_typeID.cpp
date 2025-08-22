/* #include <iostream>
#include <typeinfo> // for typeid
using namespace std;

int main() {
    int a = 10;
    double b = 20.5;
    const char* c = "Hello";

    // Using typeid to get type at runtime
    cout << "Type of a: " << typeid(a).name() << endl;
    cout << "Type of b: " << typeid(b).name() << endl;
    cout << "Type of c: " << typeid(c).name() << endl;

    // Using decltype to declare a new variable with the same type as a
    decltype(a) x = 100;   // x is int
    decltype(b) y = 300.5; // y is double

    cout << "Value of x (decltype of a): " << x << endl;
    cout << "Value of y (decltype of b): " << y << endl;

    // Using typeid with polymorphic class example
    class Base { virtual void foo() {} };
    class Derived : public Base {};
    Base* p = new Derived();

    cout << "Type of *p: " << typeid(*p).name() << endl;

    

    delete p;
    return 0;
}


 */

 #include <iostream>
#include <typeinfo>
#include <string>

int main() {
    std::string s = "hello";
    std::cout << "Type name: " << typeid(s).name() << std::endl;
    return 0;
}

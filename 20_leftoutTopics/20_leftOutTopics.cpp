#include <iostream>
#include <memory>    // For smart pointers
#include <vector>
#include <functional>

using namespace std;

// Base class with final specifier demonstration
class Base final {  // final means no class can inherit from Base
public:
    virtual void show() final {  // final means cannot override show() in derived classes
        cout << "Base::show() called\n";
    }
};

// Uncommenting below will cause compilation error because Base is final
/*
class Derived : public Base {
    void show() override {  // Error: show() is final in Base
        cout << "Derived::show() called\n";
    }
};
*/

// Class with in-class member initializers
class MyClass {
private:
    int x = 10;         // initialized in-class
    double y = 3.14;
    unique_ptr<int> sp = make_unique<int>(42);  // smart pointer initialized here

public:
    void print() {
        cout << "x = " << x << ", y = " << y << ", *sp = " << *sp << "\n";
    }
};

// Function demonstrating use of ellipsis (...) - variadic function
void printAll(const char* label, ...) {
    cout << label << ": ";

    va_list args;
    va_start(args, label);
    while (true) {
        const char* s = va_arg(args, const char*);
        if (!s) break;  // nullptr as terminator
        cout << s << " ";
    }
    va_end(args);

    cout << "\n";
}

int main() {
    // 1. auto keyword: automatic type deduction
    auto i = 100;
    auto d = 3.1415;
    auto str = string("Hello auto");

    cout << "auto variable i: " << i << ", d: " << d << ", str: " << str << "\n";

    // 2. Lambda expression
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    cout << "Lambda add(10, 20): " << add(10, 20) << "\n";

    // 3. Smart pointers (unique_ptr)
    unique_ptr<int> p = make_unique<int>(99);
    cout << "unique_ptr points to: " << *p << "\n";

    // 4. In-class initializers demo
    MyClass obj;
    obj.print();

    // 5. ellipsis: variadic function usage
    printAll("Strings", "apple", "banana", "cherry", nullptr);

    // Demonstrate Base class with final keyword
    Base b;
    b.show();

    return 0;
}

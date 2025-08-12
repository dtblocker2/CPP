/* classes and structures are almost same only difference is by default in structure verything is public

in classes by default everything is private
*/

/* 
In C++, **structures** and **classes** are almost the same — but there are a few **important differences** that matter when you’re designing code.

Let’s break it down.

---

## **1. The Main Difference: Default Access Level**

| Feature            | `struct` | `class`   |
| ------------------ | -------- | --------- |
| **Default access** | `public` | `private` |

```cpp
struct S {
    int x; // public by default
};

class C {
    int x; // private by default
};
```

---

## **2. Syntax and Capabilities**

* Both can have:

  * Member variables
  * Member functions
  * Constructors & destructors
  * Static members
  * Inheritance (structs default to *public* inheritance, classes to *private*)
  * Operator overloading

Example:

```cpp
struct MyStruct {
    int a;
    void show() { cout << a << endl; }
};

class MyClass {
    int a;
public:
    void setA(int val) { a = val; }
    void show() { cout << a << endl; }
};
```

---

## **3. Inheritance Defaults**

| Inheritance type  | `struct` default | `class` default |
| ----------------- | ---------------- | --------------- |
| Base access level | `public`         | `private`       |

```cpp
struct Base {};
struct Derived : Base {}; // public inheritance

class BaseC {};
class DerivedC : BaseC {}; // private inheritance
```

---

## **4. Common Use Cases**

* **Structs**

  * Used mostly for **plain data objects** (like C-style POD — *Plain Old Data*)
  * Often in **simple data grouping** or interop with C code
  * Example:

    ```cpp
    struct Point {
        int x, y;
    };
    ```

* **Classes**

  * Used for **full OOP**: encapsulation, abstraction, polymorphism
  * Hide implementation details and provide controlled access

---

## **5. Mixing them**

In modern C++, the only *real* difference is the default access modifier — you can make a struct behave exactly like a class and vice versa.

```cpp
struct Example {
private:
    int secret;
public:
    void setSecret(int s) { secret = s; }
};
```

This behaves exactly like a class with `public` and `private` sections.

---

## **Summary Table**

| Feature               | struct        | class    |
| --------------------- | ------------- | -------- |
| Default member access | public        | private  |
| Default inheritance   | public        | private  |
| Can have methods      | ✅             | ✅        |
| Can have constructors | ✅             | ✅        |
| Used for              | Data grouping | Full OOP |

---

If you want, I can make **one single program** that shows both struct and class side by side, with inheritance, access modifiers, and method calls so you can see their behavior directly.
Would you like me to prepare that?

*/

#include <iostream>
using namespace std;

// ---------- STRUCT EXAMPLE ----------
struct MyStructBase {
    int baseValue; // public by default
    void showBase() { cout << "Struct Base Value: " << baseValue << endl; }
};

struct MyStructDerived : MyStructBase { // public inheritance by default
    int derivedValue; // public by default
    void showDerived() { cout << "Struct Derived Value: " << derivedValue << endl; }
};

// ---------- CLASS EXAMPLE ----------
class MyClassBase {
    int baseValue; // private by default
public:
    void setBase(int val) { baseValue = val; }
    void showBase() { cout << "Class Base Value: " << baseValue << endl; }
};

class MyClassDerived : MyClassBase { // private inheritance by default
    int derivedValue; // private by default
public:
    void setDerived(int val) { derivedValue = val; }
    void showDerived() { cout << "Class Derived Value: " << derivedValue << endl; }
};

// ---------- MAIN DEMO ----------
int main() {
    cout << "=== STRUCT DEMO ===" << endl;
    MyStructDerived s;
    s.baseValue = 10;       // Accessible directly (public by default)
    s.derivedValue = 20;    // Accessible directly
    s.showBase();
    s.showDerived();

    cout << "\n=== CLASS DEMO ===" << endl;
    MyClassDerived c;
    // c.baseValue = 10;   // ❌ ERROR: baseValue is private
    // c.derivedValue = 20; // ❌ ERROR: derivedValue is private


/*     c.setBase(10);          // error ==> Must use setter
    c.setDerived(20);       // error ==> Must use setter
    c.showBase();
    c.showDerived();
 */
    return 0;
}

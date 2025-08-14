/* Here’s a clean, well-structured note set on **types of inheritance in C++** that you can directly use for study or viva prep:

---

## **Types of Inheritance in C++**

Inheritance in C++ allows a class (derived class) to acquire the properties and behaviors (data members & member functions) of another class (base class).
It supports **code reusability** and **hierarchical classification**.

---

### **1. Single Inheritance**

* **Definition:** One derived class inherits from a single base class.
* **Diagram:**

```
   Base
    ↑
 Derived
```

* **Example:**

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
    void show() { cout << "This is Parent class\n"; }
};

class Child : public Parent {
public:
    void display() { cout << "This is Child class\n"; }
};

int main() {
    Child obj;
    obj.show();
    obj.display();
}
```

* **Key Point:** Simple and straightforward; most common form.

---

### **2. Hierarchical Inheritance**

* **Definition:** Multiple derived classes inherit from the same base class.
* **Diagram:**

```
       Base
      /    \
 Derived1  Derived2
```

* **Example:**

```cpp
class Animal {
public:
    void eat() { cout << "Eating...\n"; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking...\n"; }
};

class Cat : public Animal {
public:
    void meow() { cout << "Meowing...\n"; }
};

int main() {
    Dog d;
    Cat c;
    d.eat(); d.bark();
    c.eat(); c.meow();
}
```

* **Key Point:** Useful when several classes share common features.

---

### **3. Multilevel Inheritance**

* **Definition:** A chain of inheritance where a class is derived from another derived class.
* **Diagram:**

```
   Base
    ↑
Derived1
    ↑
Derived2
```

* **Example:**

```cpp
class Grandparent {
public:
    void property() { cout << "Has family property\n"; }
};

class Parent : public Grandparent {
public:
    void skills() { cout << "Has parenting skills\n"; }
};

class Child : public Parent {
public:
    void hobbies() { cout << "Has hobbies\n"; }
};

int main() {
    Child c;
    c.property();
    c.skills();
    c.hobbies();
}
```

* **Key Point:** Inheritance depth can be as long as needed.

---

### **4. Multiple Inheritance**

* **Definition:** A single derived class inherits from more than one base class.
* **Diagram:**

```
  Base1   Base2
     \    /
     Derived
```

* **Example:**

```cpp
class Teacher {
public:
    void teach() { cout << "Teaching students\n"; }
};

class Researcher {
public:
    void research() { cout << "Doing research\n"; }
};

class Professor : public Teacher, public Researcher {
public:
    void guide() { cout << "Guiding projects\n"; }
};

int main() {
    Professor p;
    p.teach();
    p.research();
    p.guide();
}
```

* **Key Point:** Can lead to **ambiguity** if both base classes have functions with the same name — resolved using **scope resolution**.

---

✅ **Extra Notes:**

* **Access Specifiers in Inheritance:**

  * **Public**: Public → Public, Protected → Protected, Private → Not inherited.
  * **Protected**: Public & Protected members → Protected, Private → Not inherited.
  * **Private**: All inherited members become private.

* **Virtual Base Class:** Used to avoid ambiguity in **diamond problem** of multiple inheritance.

---

If you want, I can also make a **single-page summarized diagram** showing all four inheritance types with examples for quick revision. That will help in viva.
 */

/* 
Got it — you probably mean **"Hybrid" (Multipart) Inheritance** in C++,
where multiple types of inheritance are combined in one structure.

Here are clear, exam-friendly notes:

---

## **Multipart (Hybrid) Inheritance in C++**

**Definition:**
Multipart or **Hybrid Inheritance** is a combination of two or more basic types of inheritance (single, multiple, multilevel, hierarchical) in a single program.
It allows more complex relationships between classes.

---

### **Example Structure**

```
        Base1     Base2
           \      /
           Derived1
              ↑
          Derived2
```

This could combine **multiple** and **multilevel** inheritance.

---

### **Key Points**

* Useful for modeling **real-world problems** that can’t be represented by a single type of inheritance.
* May cause **ambiguity** (e.g., *Diamond Problem*) when a base class is inherited multiple times through different paths.
* **Virtual inheritance** is used to resolve ambiguity.

---

### **Code Example (Hybrid)**

```cpp
#include <iostream>
using namespace std;

// Base class
class Person {
public:
    void showName() { cout << "Name: John\n"; }
};

// Another base class
class Worker {
public:
    void showJob() { cout << "Job: Engineer\n"; }
};

// Derived from multiple bases
class Employee : public Person, public Worker {
public:
    void showID() { cout << "ID: 101\n"; }
};

// Further derived (multilevel)
class Manager : public Employee {
public:
    void showRole() { cout << "Role: Project Manager\n"; }
};

int main() {
    Manager m;
    m.showName();  // From Person
    m.showJob();   // From Worker
    m.showID();    // From Employee
    m.showRole();  // From Manager
}
```

---

### **Diamond Problem in Hybrid Inheritance**

Occurs when a base class is inherited by multiple classes and then a derived class inherits from those classes.
**Problem:** Duplicate copies of base class members.

**Example:**

```
    A
   / \
  B   C
   \ /
    D
```

If both `B` and `C` inherit from `A`, `D` gets two copies of `A`.

**Solution:** Use `virtual` inheritance.

```cpp
class A { ... };
class B : virtual public A { ... };
class C : virtual public A { ... };
class D : public B, public C { ... };
```

---

✅ **Summary Table for Multipart (Hybrid) Inheritance:**

| Feature           | Explanation                                    |
| ----------------- | ---------------------------------------------- |
| Definition        | Combination of two or more inheritance types   |
| Benefit           | Models complex real-world relations            |
| Risk              | Ambiguity, redundancy                          |
| Fix for Ambiguity | Virtual base classes                           |
| Common Combo      | Multiple + Multilevel, Hierarchical + Multiple |

---

If you want, I can make you a **one-page diagram** showing Single, Multiple, Multilevel, and Hybrid with arrows so it’s easier to remember in exams. That visual would make multipart inheritance crystal clear.

*/
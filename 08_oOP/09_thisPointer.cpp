#include <iostream>

using namespace std;

class Rectangle {
    private:
        float breadth;
        float length;

    public:
        Rectangle(int length, int breadth) {
            this->length = length;
            this->breadth = breadth;
            // same as self in python
        };

        float area() {
            return this->length*this->breadth;
        };

        float perimeter() {
            return 2*(this->length+this->breadth);
        };
};

int main() {
    Rectangle r1(10,20);
    cout<<r1.area()<<endl;
    cout<<r1.perimeter()<<endl;
    
return 0;
};

/* 
Your code works fine — you’re using `this->` to refer to the current object’s members, which is very similar to `self` in Python.

A few key points worth noting about this version:

---

### 1. Why use `this->`?

* Inside a class method, `this` is an **implicit pointer** to the object that’s calling the method.
* So `this->length` means “the `length` member of this object.”
* You only *need* to use `this->` when there’s ambiguity between a parameter and a member variable (like in your constructor here where both have the same name).

---

### 2. Without `this->`

You could also write the constructor like this and get the same result:

```cpp
Rectangle(int length, int breadth) {
    this->length = length;   // explicit
    this->breadth = breadth;
}
```

Or using different parameter names to avoid `this->` entirely:

```cpp
Rectangle(int l, int b) {
    length = l;
    breadth = b;
}
```

---

### 3. Even cleaner — **initializer list**

Instead of assigning inside the constructor body, you can use an initializer list for better performance:

```cpp
Rectangle(int length, int breadth)
    : length(length), breadth(breadth) {}
```

This initializes members directly rather than default-constructing them first and then assigning values.

---

### 4. Your output

For the given input `(10, 20)`:

```
200
60
```

That’s correct:

* Area = `10 × 20 = 200`
* Perimeter = `2 × (10 + 20) = 60`

---

If you want, I can rewrite this same example but **add debug prints** showing what `this` actually contains (its memory address) so you can see that it’s really a pointer to the calling object. That’s a neat trick for understanding `this` deeply.
*/
// it is example of polymorphism ==> child are different but under some certain category

/* 
Here’s a **simple C++ example** to clearly show **Generalization** vs **Specialization** in Object-Oriented Programming.

---

## **Concept Recap**

* **Generalization**

  * Moving from **specific** classes to a **more general** base class.
  * Common features are **abstracted** into a parent class.
  * Example: `Car` and `Bike` → common `Vehicle` class.

* **Specialization**

  * Moving from a **general** class to **more specific** derived classes.
  * Adding unique features in the child classes.
  * Example: `Vehicle` → `Car` and `Bike` classes.

---

### **Explanation**

* **Generalization**

  * `Vehicle` is created to hold features common to all vehicles (`brand`, `speed`, `showBasicInfo`).
  * This prevents code duplication.

* **Specialization**

  * `Car` adds `doors`.
  * `Bike` adds `hasGear`.
  * They **inherit** from `Vehicle` and extend functionality.

---

### **Visual**

```
[Generalization]
Car --------\
             → Vehicle (Generalized class)
Bike -------/

[Specialization]
Vehicle → Car (doors)
        → Bike (hasGear)
```

---

If you want, I can also make **one single code** that shows **both processes happening together** — starting from specialized classes, generalizing them, and then specializing again — so you can demonstrate both directions in the same example for viva. That’s a common professor trick question.

*/

#include <iostream>
using namespace std;

// GENERALIZATION:
// Common features of Car and Bike are put in Vehicle.
class Vehicle {
public:
    string brand;
    int speed;

    Vehicle(string b, int s) : brand(b), speed(s) {}

    void showBasicInfo() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

// SPECIALIZATION:
// Car adds features specific to cars.
class Car : public Vehicle {
public:
    int doors;

    Car(string b, int s, int d) : Vehicle(b, s), doors(d) {}

    void showCarInfo() {
        showBasicInfo();
        cout << "Doors: " << doors << endl;
    }
};

// SPECIALIZATION:
// Bike adds features specific to bikes.
class Bike : public Vehicle {
public:
    bool hasGear;

    Bike(string b, int s, bool g) : Vehicle(b, s), hasGear(g) {}

    void showBikeInfo() {
        showBasicInfo();
        cout << "Has Gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};

int main() {
    // Specialization: Car object with extra info
    Car c("Toyota", 180, 4);
    cout << "[Car Info]\n";
    c.showCarInfo();

    // Specialization: Bike object with extra info
    Bike b("Yamaha", 120, true);
    cout << "\n[Bike Info]\n";
    b.showBikeInfo();

    return 0;
}

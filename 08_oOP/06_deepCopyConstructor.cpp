#include <iostream>
using namespace std;

// --------- SHALLOW COPY VERSION ----------
class ShallowRectangle {
    float* length;
    float* breadth;

public:
    ShallowRectangle(float l=1, float b=2) {
        length = new float(l);
        breadth = new float(b);
    }

    // Default copy constructor (compiler-provided) does SHALLOW copy
    // This means it just copies the pointer addresses!

    void set_length(float l) { *length = l; }
    void set_breadth(float b) { *breadth = b; }

    void show_data() {
        cout << "Length: " << *length << " Breadth: " << *breadth << endl;
    }

    ~ShallowRectangle() {
        delete length;
        delete breadth;
    }
};

// --------- DEEP COPY VERSION ----------
class DeepRectangle {
    float* length;
    float* breadth;

public:
// constructor functions
    DeepRectangle(float l=1, float b=2) {
        length = new float(l);
        breadth = new float(b);
    }

    // Deep copy constructor
    DeepRectangle(const DeepRectangle &r) {
        length = new float(*r.length);   // create new memory & copy value
        breadth = new float(*r.breadth); // create new memory & copy value
    }

        // setters/mutators function
    void set_length(float l) { *length = l; }
    void set_breadth(float b) { *breadth = b; }
    // accessor function
    void show_data() {
        cout << "Length: " << *length << " Breadth: " << *breadth << endl;
    }

    // facilatator functions
    float area() {
            return (*length)*(*breadth);
        };
    float perimeter() {
        return 2*(*length+*breadth);
    };

    // validator/enquiry functions
    bool is_square() {
        if (*length == *breadth){
            return true;
        };
        return false;
    };

    // destroyer function
    ~DeepRectangle() {
        delete length;
        delete breadth;
    }
};

int main() {
    cout << "=== SHALLOW COPY DEMO ===\n";
    ShallowRectangle s1(10, 20);
    ShallowRectangle s2 = s1; // shallow copy (default constructor)

    cout << "Before change:\n";
    s1.show_data();
    s2.show_data();

    s1.set_length(99); // change in s1 also affects s2
    cout << "After changing s1 length to 99:\n";
    s1.show_data();
    s2.show_data();

    cout << "\n=== DEEP COPY DEMO ===\n";
    DeepRectangle d1(10, 20);
    DeepRectangle d2 = d1; // deep copy (custom constructor)

    cout << "Before change:\n";
    d1.show_data();
    d2.show_data();

    d1.set_length(99); // change in d1 does NOT affect d2
    cout << "After changing d1 length to 99:\n";
    d1.show_data();
    d2.show_data();

    return 0;
}

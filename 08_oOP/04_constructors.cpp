#include <iostream>

using namespace std;

class Rectangle {
    private:
        float length;
        float breadth;

    public:
        // constructor must be in public and must have same name as class name

    // default constructor
    // if no inputs ==> non parameterize
        Rectangle() {
            length = 1;
            breadth = 2;
        };

        // if inputs are given as float ==> parametrize constructor
        Rectangle(float l, float b) {
            length = l;
            breadth = b;
        };

        // if input is another rectangle ==> copy constructor
        Rectangle(Rectangle &r) {
            length = r.length;
            breadth = r.breadth;
        };

        float area() {
            return length*breadth;
        };

        float perimeter() {
            return 2*(length+breadth);
        };

        void show_data() {
            cout<<"length: "<<length<<" breadth: "<<breadth<<endl;
        };
};

int main() {
    /* types of cinstructor
    1. Default constructor
    2. Non parameterize ie default constructor
    3. parameterize
    4. copy constructor
    */
    
    Rectangle r1(10,20);
    r1.show_data();

    Rectangle r2; // if no data is provided then default value will be shown iw from Rectangle() function only ==> same idea as in theory that functions that have same name but different number of parameter ==> only those with same no of parameter as input values will be executed
    r2.show_data();

    Rectangle r3(r1);
    r3.show_data();

    /* Rectangle r4();
    r4.show_data(); // error */

    Rectangle r4{};
    r4.show_data();

    return 0;
};

/* 
3. Why Rectangle r4(); causes an error
This line:

Rectangle r4();
does not create an object!
In C++, this is parsed as a function declaration named r4 that returns a Rectangle and takes no parameters — known as the most vexing parse problem.

To create an object with the default constructor, you should just write:

Rectangle r4;
or:

Rectangle r4{}; // C++11 uniform initialization
*/
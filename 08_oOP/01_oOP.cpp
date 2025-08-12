#include <iostream>

using namespace std;

class Rectangle {
    public:
        float length;
        float breadth;

        float area() {
            return length*breadth;
        };

        float perimeter() {
            return 2*(length+breadth);
        };
};

int main() {
    /* 
    Principles of OOP:
    
    1. Abstraction ==> no need to know how function works but just use them. hidden processing only parta that user need is visible
    2. Encapsulation ==> preventing direct access to read/edit some data, to prevnt mishandling and in some cases security 
        -data handling
    3. Inheritence
    4. Polymorphism
    */

    // class My {
    //     private:
    //         int x=10;

    //     public:
    //         int y = 20;

    //         int call_x() {
    //             return x;
    //         };

    // };

    /* 
    Class vs Objects

    class is group of objects ==> define group

    object are defined according to a class.
    */

    // classes are used as user defined datatypes
    Rectangle r1,r2,r3; // storage used by objects r1,r2 and r3 are 8 bytes each ie 4 bytes for length and 4 bytes for breadth for each object

    // dot operators ==> to assigne value to variable in class
    r1.length =10; // we can use it unless they are defined under public because by default they are private
    r1.breadth = 20;

    cout<<r1.area()<<endl;

    r2.length =10;
    r2.breadth = 2;
    cout<<r2.perimeter()<<endl;

    r3.length =1;
    r3.breadth = 2;
    cout<<r3.area()<<endl;
    cout<<r3.perimeter()<<endl;
   
    return 0;
};
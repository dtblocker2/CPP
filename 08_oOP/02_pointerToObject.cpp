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
    Rectangle r;
    Rectangle *p;

    p = &r;

    r.length=10;
    // arrow operator ==> used for pointer instead of dot operator
    p->breadth=5;

    cout<<p->perimeter()<<endl;
    cout<<r.area()<<endl;

    // you can also create new class and poin pointer q to it to create obkect in heap and point q to it rather than creating r in stack then pointing p to it
    Rectangle *q = new Rectangle;

    q->length=8;
    q->breadth=22;

    cout<<q->perimeter()<<endl;
    cout<<q->area()<<endl;

    return 0;
};
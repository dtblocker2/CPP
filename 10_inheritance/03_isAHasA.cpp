#include <iostream>

using namespace std;

class Rectangle {
    private:
    int length;
    int breadth;

    public:
    Rectangle (int l=1, int b=2) {
        this->length = l;
        this->breadth = b;
    };

    int getLength() {
        return length;
    };

    int getBreadth() {
        return breadth;
    };

    void setLength(int l) {
        length = l;
    };

    void setBreadth(int b) {
        breadth = b;
    };

    int area() {
        return length*breadth;
    };

    int perimeter() {
        return 2*(length*breadth);
    };
};

class Cuboid:public Rectangle {
    private:
    int height;

    public:
    Cuboid(int l=1, int b=2, int h=3) {
        this->height = h;
        this->setLength(l);
        this->setBreadth(b);
    };

    int getHeight() {
        return height;
    };

    void setHeight(int h) {
        height = h;
    };

    int volume() {
        return getLength()*getBreadth()*height;
    };

    int perimeter() {
        return 4*(getLength()+getBreadth()+height);
    };

    int surfaceArea() {
        return 2*(getLength()*getBreadth()+height*getLength()+getBreadth()*height);
    };
};

// having object of other class in one class eg using rectangle class to make top of class table
class Table {
    public:
    Rectangle top;
    int legs;
};

/* 
if class M is inherited from class N then it has isA relation
if class M has object of class N then it has hasA relation
*/

/* types of members in class:
1. private
2. public
3. protected
*/

int main() {

    return 0;
};

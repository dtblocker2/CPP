#include <iostream>

using namespace std;

// Parent class
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

// child class that extends parent class ie height and breadth parameters will be inherited only new parameter ie depth is added in cuboid
// it is achieved using extend parameter ie (:)
class Cuboid:public Rectangle {
    private:
    int height;

    public:
    // to make constructor of child class parent class must have a default constructor ie non parameterize on or one with default parameter in parameterize one
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

// or we can use
class Base {
    public:
    int x;

    void show() {
        cout<<x<<endl;
    };
};

class Derived:public Base {
    public:
    int y;

    void display() {
        cout<<x<<" "<<y<<endl;
    };
}; 


int main() {
    // object of base and derived class
    Base b;
    b.x=5;
    b.show();

    Derived d;
    d.x=10;
    d.y=20;
    d.show();
    d.display();

    Cuboid c(5);
    cout<<c.getLength()<<endl; // 5==> input value
    cout<<c.getBreadth()<<endl; // 2==> default value
    cout<<c.getHeight()<<endl; // 3==> default value
    cout<<c.volume()<<endl;

    return 0;
};
#include <iostream>

using namespace std;

class Rectangle {
    private:
        float length;
        float breadth;

    public:
        // instead of using below you can give default value in second function to reduce code ie constructor function overloading
        /* Rectangle() {
            length = 1;
            breadth = 2;
        }; */

        Rectangle(float l=1, float b=2) {
            length = l;
            breadth = b;
        };

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
    Rectangle r1;
    r1.show_data();

    return 0;
};

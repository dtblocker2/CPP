#include <iostream>

using namespace std;

class Rectangle {
    private:
        float length;
        float breadth;

    public:
        int name;

        Rectangle(float l=1, float b=2, int n=0) {
            length = l;
            breadth = b;
            name = n;
        };

        Rectangle(Rectangle &r) {
            length = r.length;
            breadth = r.breadth;
        };

        // here area is defined inside class so it is inline
        float area() {
            return length*breadth;
        };

        // use inline to make non inline function as inline ie its machine code will be generated inside main() function only where it was called in main()
        inline float perimeter();
        
        void show_data() {
            cout<<"length: "<<length<<" breadth: "<<breadth<<endl;
        };
        
        // destructor
        ~Rectangle() {
            cout<<"Rectangle"<<name<<" destroyed"<<endl;
        };
    };
    
// here although perimeter is defined outside but inline is used so it is inline
float Rectangle::perimeter() {
    return 2*(length+breadth);
};

int main() {
    Rectangle r1(10,20,1);
    cout<<r1.area()<<endl;
    cout<<r1.perimeter()<<endl;
    
return 0;
};

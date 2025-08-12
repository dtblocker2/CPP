#include <iostream>

using namespace std;

class Rectangle {
    private:
        float length;
        float breadth;

    public:
        int name;
        // if some of parameter in function are given default value then all must be given default values too.
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

        // here perimeter is defined outside class so it is non inline
        float perimeter();

        void show_data() {
            cout<<"length: "<<length<<" breadth: "<<breadth<<endl;
        };

        // destructor
        ~Rectangle() {
            cout<<"Rectangle"<<name<<" destroyed"<<endl;
        };
};

// writing function outside class ==> non -inline
float Rectangle::perimeter() {
    return 2*(length+breadth);
};

/* what is difference

during compilation all function in class that are called in code get generated below the call function ie machine code of area() function in this case is generated in main() function only below where r1.area() is called

but in scope resolution function where function is called then machine code will come out of main() function then execute perimeter() function then get back to main() function
*/
int main() {
    Rectangle r1(10,20,1);
    // in line function
    cout<<r1.area()<<endl;
    // non inline function
    cout<<r1.perimeter()<<endl;

    // in line function must be simple to reduce compilation time ==> simple function inside class ==> use scope resolution to create complex function outside class eg iterator functions

    // it makes function easy to read ie less space between different function and variable ==> scope resolution make code faster to compile and easy to read

    int query;
    cout<<"Do you want to create r2: (0/1)"<<endl;
    cin>>query;

    if (query) {
        Rectangle r2(4,8,2);
        cout<<r2.area()<<endl;
        cout<<r2.perimeter()<<endl;
    };

    cout<<"If 'Rectangle2 destroyed' is above this line then r2 is destroyed just after if conditional block ended"<<endl;

    // cout<<r2.area()<<endl; // error as r2 is destroyed

    return 0;
};

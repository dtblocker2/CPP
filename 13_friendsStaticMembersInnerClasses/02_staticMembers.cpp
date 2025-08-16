// can a function access all the members of class ie public, protected and private

#include <iostream>

using namespace std;

class Test {
    private:
    int a;
    int b;

    public:
    static int count; // we already discussed this

    Test() {
        a=10;
        b=10;
        count++;
    };

    // static function can only access static data memebers
    static int counter() {
        // a+; //error as 'a' variable is not a static data member
        return count; 
    };
};

// static variable must be declared outside class to because inside class we can not assign it initial value
int Test::count = 0; // dont forget to use scope resolution

int main() {
    Test t1;
    Test t2;

    // to access it you can use class object attributes
    cout<<t1.count<<endl;
    cout<<t2.count<<endl;
    // or scope resolution
    cout<<Test::count<<endl;

    Test t3;

    // same for static member functions too
    cout<<t3.counter()<<endl;
    cout<<Test::counter()<<endl;

    /* uses:
    1. access function or variable in class such as count or counter
    without need to create new object for eg
    you created class car and price can be static member we can know price by using Car::getPrice() static function
    ie no need to create any object like Car c1;
    then using c1.getPrice()

    2. like in scenerio we can create static object admisssion number and create roll number variable after student list is parsed 
    admission number increases with each student and thus we store it in roll number of each student at last admission number static vaiable is discarded
    */

    return 0;
};
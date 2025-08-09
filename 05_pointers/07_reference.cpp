#include <iostream>
using namespace std;

main() {
    int x = 10;

    // declaration and initialization of reference must be done simultaneously
    int &y = x; // now both x and y will point toward memory location where 10 is stored ie change in x will change y and vice versa
    int a = x; //here a have different memory location so changing x wont change a

    x = x-1;
    cout<<"x: "<<x<<" y: "<<y<<endl;

    y = 100;
    cout<<"x: "<<x<<" y: "<<y<<endl;
    cout<<"a: "<<a<<endl;

    return 0;
};
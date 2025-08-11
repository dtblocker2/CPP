#include <iostream>

using namespace std;

void swap_by_value(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout<<"Inside function: a= "<<a<<" b= "<<b<<endl;
};

void swap_by_address(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cout<<"Inside function: a= "<<*a<<" b= "<<*b<<endl;
};

void swap_by_reference(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout<<"Inside function: a= "<<a<<" b= "<<b<<endl;
};

int main() {
    /* Meathods of parameter passsing in function:
    1. pass by value
    2. pass by reference
    3.  pass by address */

    // Pass by value
    int x=10, y=20;
    swap_by_value(x,y);
    cout<<"Outside function: x= "<<x<<" y= "<<y<<endl; // it won't swap rather it will only take value of x and y and not real x and y so use pass by address

    //  x and y are actual parameter and a and b are formal parameter so pass by value only change formal paramters and not actual ones

    // pass by address
    swap_by_address(&x,&y); // pass pointers instead of value of x and y
    cout<<"Outside function: x= "<<x<<" y= "<<y<<endl;

    // resetting values
    x=10,y=20;
    cout<<"reset x= "<<x<<" y= "<<y<<endl;
    swap_by_reference(x,y); // not need pass pointers instead pass x and y unlike in pass by address
    cout<<"Outside function: x= "<<x<<" y= "<<y<<endl;

    // call by reference is written different in code but during compilation it is inserted between code section in machine code so big and complex function which use pass by reference must not be used more number of times

    return 0;
};
#include <iostream>

using namespace std;

// global variable
int g = 0;
/* 
memory to globakl ariable si  given in code section only variable in functions get their value stored in stack
it stay till code is executed
*/

void counter() {
    g++; // g is accessible in counter()

    // cout<<l<<endl; // error as l is not accessible in counter()
};

int main() {
    // local variable
    int l = 0; // not accessible to counter()

    for (int i=0; i<20; i++) {
        counter();
        cout<<g<<endl; // g is accessible in main() too
    };

    return 0;
};
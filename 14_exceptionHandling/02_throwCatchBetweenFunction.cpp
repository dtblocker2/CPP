/* 
Types of errors:
1. Syntax Error ==> in compiler
2. Logical Error ==> use debugger to solve them
3. Runtime Error ==> e.g. wrong type of input, no internet connection etc.
*/

#include <iostream>

using namespace std;

int division(int a, int b) {
    if (b==0) {
        // you can throw any datatype or object of any class as it will be catch by catch block
            throw 'A';
        };
    return a/b;
};

int main() {
    int a=10, b=0, c;

    try {
        // we can catch error thrown by function
        c = division(a,b);
        cout<<c<<endl;
    } catch(char e) {
        cout<<"Division by zero not allowed "<<e<<endl;
    };

    return 0;
};
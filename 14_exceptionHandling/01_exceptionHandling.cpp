/* 
Types of errors:
1. Syntax Error ==> in compiler
2. Logical Error ==> use debugger to solve them
3. Runtime Error ==> e.g. wrong type of input, no internet connection etc.
*/

#include <iostream>

using namespace std;

int main() {
    int a=10, b=0, c;

    try {
        if (b==0) {
            throw 1;
        };
        c = a/b;
        cout<<c<<endl;
    } catch(int e) {
        cout<<"Division by zero not allowed "<<e<<endl;
    };

    return 0;
};
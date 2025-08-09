#include <iostream>

using namespace std;

int main() {
    /* five operation allowed using pointer
    1. p++ ==> pointer moves to next location
    2. p-- ==> pointer mover backward
    */

    int A[5] = {12,32,43,46,75};
    int *p = A, *q = &A[3];

    cout<<p<<endl;
    cout<<*p<<endl;

    // 1. increment operator will increase location
    p++;
    cout<<p<<endl;
    cout<<*p<<endl;

    // 2. decrement operator will increase location
    p--;
    cout<<p<<endl;
    cout<<*p<<endl;

    // 3. coumpound operators
    p += 3;
    cout<<p<<endl;
    cout<<*p<<endl;

    p -= 2;
    cout<<p<<endl;
    cout<<*p<<endl;

    cout<<p<<" "<<q<<endl;
    cout<<"p-q = [(adress of p)-(addresof q)]/2 \ndivided by 2 because int are used and their sizes of memmory location is 2: "<<q-p<<endl;

    /* if you getting +ve then q if further awy and if it is -ve then p is further away pointer */

    return 0;
};

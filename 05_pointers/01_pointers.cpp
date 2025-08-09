#include <iostream>
using namespace std;

int main() {
    /* types of variables:
    1. data variables
    2. address variables
    */

    // datav ariable
    int x = 10;

    // address variable
    int *p; // declaration of pointers of int datatype

    // saving address to p ie pointing to x
    p = &x; // initialzing using reference operator ie &

    cout<<x<<endl; // value of x
    cout<<&x<<endl; // adress of x ie stored in p

    cout<<p<<endl; // adress of x ie value of p
    cout<<&p<<endl; // address of p

    cout<<*p<<endl; // value of x (dereferencing)

    // change in *p bring change in x but don't use increment or decrement operator because
    *p += 1;
    cout<<x<<" "<<*p<<endl; // 11 11
    return 0;

    *p++;
    cout<<x<<" "<<*p<<endl; // ---nothing---
    return 0;
};
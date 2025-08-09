#include <iostream>
using namespace std;

int main() {
    /* heap memory is allocated dynamically so it is decided at run time not at compilation time
    do use pointer to predefine them
    */

    int A[5] = {1,2,3,4,5};
    // this array is created in stack on declaration
    
    int *p; // this pointer is also stored in stack

    // but when we use new int[5] this int[5] gets declared in heap and its memory gets stored in p in stack
    p = new int[5]; // new int[5] is stored in heap and its address is stored in p which is stored in heap

    // so variables declared in code gets stored in heap and dynamically declared variable like new int[5] ie declared during run time get declared in heap
    // so we can get address of variables in stack using &x
    /* 
    but in order to get address of variable in heap there who have no name
    we can make pointer p then point it toward that dynamically declared variable in heap and then print is value to get their address
    */

    /* when array is declared in stack it automatically gets deleted when out of scope of the function but this is not in case of dynamically declared variables ie those which are stored in heap
    
    so it may cause memory issues
    it will be there as long as program is running

    so we need to deallocat them after their work has been done

    use delete []p ==> []p because here we declared p as array here
    */

    p[2] = 10;
    cout<<p[2]<<endl;
    cout<<p[1]<<endl; // random ass value because we did not defined p[0]

    delete []p;
    cout<<p<<endl;
    // if we don't do this this may lead to memory leak problem

    // is p = nullptr; the pointer is not pointing anywhere
    p = nullptr;
    cout<<p<<endl; // 0

    return 0;
};

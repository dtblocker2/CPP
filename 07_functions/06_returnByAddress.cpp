#include <iostream>

using namespace std;

// return by address
int * fun() {
    int *x = new int[5];

    for (int i=0; i<5; i++) {
        x[i] = 5*i;
    };
    
    cout<<"address of x="<<x<<endl;
    return x;
};

// return by reference
int & fun2(int &x) {
    
    return x;
};

int main() {
    int *y = fun();
    cout<<"address of y="<<y<<endl;

    int a=10;
    cout<<a<<endl;

    // due to return by reference fun2(a) itself point toward a so we can do stuff liike
    fun2(a) = a+22; // 10 + 22 = 32 ==> now fun2(a) is also pointing to a so it becomes a = 32
    cout<<a<<endl;

    return 0;
};
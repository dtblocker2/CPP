#include <iostream>

using namespace std;

void fun() {
    // static variable are declared on time ie call at first tile after that their value won't be change on declareation ie
    static int a = 0;
    int b= 0;
    a++;
    b++;
    cout<<a<<" "<<b<<endl; // a will change but b won't
};

int main() {
    fun();
    fun();
    fun();
    fun();
    fun();

    return 0;
};
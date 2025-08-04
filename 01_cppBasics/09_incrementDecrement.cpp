#include <iostream>
using namespace std;

int main()
{
    /* 
    pre increment
    ++x

    post increment
    x++

    pre decrement
    --x

    post decrement
    x--
    */
    int i = 0;
    cout << i++; // 0 as it is increased after printed
    cout << ++i; // 2 as it was 1 and increased before printing

    // similarly
    int x,y;
    x = 5;
    y = x--; // x= 4 but y = 5 and x is decreased after assigned its value to y
    cout << x << y; // 4 5

    y = --x; // x = 3 and y = 3 as x is first decreased then assigned
    cout << x << y; // 3 3

    return 0;
}

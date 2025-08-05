#include <iostream>
using namespace std;

int main()
{
    /* 
    & And
    | Or
    ^ X-Or
    ~ Not
    >> Right Shift
    << Left Shift
    */

    int x,y,z;
    x = 5;
    y = 11;

    // OR
    z = x | y;
    cout << z << endl; // (00000101) OR (00001011) == (00001111) == 15

    // AND
    z = x & y;
    cout << z << endl;

    // NOT
    z = ~ x;
    cout << z << endl; // -6 because NOT of (00000101) == (11111010) ==> -128 + 64 + 32 + 16 + 8 + 2 ==> -6
    // because here we use signed integers so MSB denotes negative number if it was unsigned then answer would have been 250

    // XOR
    z = x ^ y;
    cout << z << endl;

    // left shift
    z = x | y;
    cout << z << endl;

    return 0;
};

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int b,h;
    cout << "Input base and height in order: ";
    cin >> b >> h;

    float area = (float) (b*h/2);
    cout << "Area is: " << area;

    // printing imaginary number
    int a = -1;
    cout << sqrt(a); // nan ==> Not a Number

    return 0;

};

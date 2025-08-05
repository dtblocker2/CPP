#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float r,area; // float can't be unsigned
    cout << "Enter radius of Circle: ";
    cin >> r;

    area = pow(r,2)*M_PI;

    cout << "Area is :" << area;

    return 0;
}

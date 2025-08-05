#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float s,a,d,n; // float can't be unsigned
    cout << "Basic Salary, Percentage allowance and percentage deductio in order:  ";
    cin >> s >> a >> d; // don't use s,a,d

    n = s+s*a/100-s*d/100;

    cout << "Net Salary is :" << n;

    return 0;
}

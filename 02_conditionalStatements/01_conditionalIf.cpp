/* if consitional statement only checks for integers not for float and if input is 0 then its false else its true even for negative numbers */

#include <iostream>

using namespace std;

int main() {
    int a,b;

    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    if (a > b) {
        cout << "A is greater";
    } else if (a == b) {
        cout << "Both arer equal";
    } else {
        cout << "B is greater";
    };

    return 0;
};

#include <iostream>

using namespace std;

int main() {
    int m1,m2,m3,total;

    cout << "Enter yout marks: ";
    cin >> m1 >> m2 >> m3;

    total = (m1+m2+m3)/3;

    if (total >= 60) {
        cout << "A";
    } else if ((total < 60) && (total >= 35)) {
        cout << "B";
    } else {
        cout << "C";
    };

    return 0;
}

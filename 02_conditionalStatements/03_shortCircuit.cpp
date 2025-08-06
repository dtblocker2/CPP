#include <iostream>

using namespace std;

int main() {
    int a = 5, b=14, c=1;
    if (a>b && a++>c) {
        // in above case a>b is false and we have AND logical operation so output is false hence compiler won't check further as any one of input in AND operation is false hence value of a won't increase due to a++ operator
    };

    cout << a << endl;

    if (a<b || a++>c) {
        // in above case a<b is true and we have OR logical operation so output is true hence compiler won't check further as any one of input in OR operation is true hence value of a won't increase due to a++ operator
    };

    cout << a;

    return 0;
};

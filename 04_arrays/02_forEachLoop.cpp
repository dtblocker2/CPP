#include <iostream>

using namespace std;

int main() {
    int A[] = {1,2,31,34};
    // For Each loop
    for (int x:A) {
        cout<<x<<endl;
        x += 1;
        cout<<x<<endl;
    };

    // even though x +=1 is used value of array's element is same because x is xopy of that element no actual element
    for (int x:A) {
        cout<<x<<endl;
    };

    // to do it use
    A[2] = 69;
    cout<<A[2]<<endl;

    // or use reference (&) will also give x reference to that value so modifying x will modify value of element of that array
    for (int &x:A) {
        x+=1;
    };

    for (int &x:A) {
        cout<<x<<endl;
    };

    // define x auto to dynamically access datatype
    // auto can be used to normal variables too
    auto x = 1.5;
    cout<<x<<endl;

    for (auto x:A) {
        cout<<x<<endl;
    };

    return 0;
};
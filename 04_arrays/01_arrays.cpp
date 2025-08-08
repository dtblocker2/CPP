#include <iostream>
#include <string>

using namespace std;

int main() {
    /* create array of 10 integers */
    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    // o indexed list so to print first element use
    cout << A[0] << endl;

    // cout << A won't print whole array
    cout << A << endl; // it will print its memory address

    // for loop to print A
    for (int i=0; i < 10; i++) {
        cout << A[i] << endl;
    };

    // declaring array less than declared size is possible but not more than that. undefined numbers in array will be 0 or blank in case of char datatype
    char B[5] = {'a','b'};
    int D[5] = {1,2};

    for (int i=0; i < 5; i++) {
        cout << D[i] << endl;
    };

    // we can declare like below and add as many time of input but be sure no of input will be size of array
    int C[] = {3,4,23,53}; // as we have 4 int in it so its size will be 4

    // for loop for arrays
    for (int x:C) {
        cout << x << endl;
    };

    // this array will print zero if size of array is define and no of element are less that that
    for (int x:D) {
        cout << x << endl;
    };

    // also accessinf element x datatype must match datatype of elements in array
    float E[] = {2.5f,5.6f,2,4.9f,7};

    for (int x:E) {
        cout << x << endl;
    };

    for (float x:E) {
        cout << x << endl;
    };

    // define x auto to dynamically access datatype
    // auto can be used to normal variables too
    auto x = 1.5;
    cout<<x<<endl;

    for (auto x:E) {
        cout<<x<<endl;
    };

    return 0;
};

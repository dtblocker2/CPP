#include <iostream>
#include <climits>

using namespace std;

int main() {
    /* condition:
    elements must be sorted
    */
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int minA,maxA;

    // in order to do it minA must be least number ideally it must be -inf but here we use int so it must be least of int ie INT_MIN from climits library
    maxA = INT_MIN;
    minA = INT_MAX;
    
    // or use
    maxA = A[0];
    minA = A[0];

    // use exit to stop commands below eg
    exit(0);
    cout<<"this wont get printed";
    return 0;
};
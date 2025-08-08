#include <iostream>

using namespace std;

int main() {
    /* condition:
    elements must be sorted
    */
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int b,n=0,mid,l=0,h=20,z,mid_prev;

    cin>>b;

    // binary search
    while (true) {
        mid = (l+h)/2;

        z = A[mid];

        if (mid_prev == mid) {
            cout<<b<<" not in list"<<endl;
            break;
        };
        if (A[mid] == b) {
            cout<<"Found: "<<b<<endl;
            break;
        };

        if (A[mid]>b){
            h=mid;
        };

        if (A[mid]<b){
            l=mid;
        };

        mid_prev = mid;
    };


    return 0;
};
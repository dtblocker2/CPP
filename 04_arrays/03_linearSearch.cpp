#include <iostream>

using namespace std;

int main() {
    int A[10] = {6,11,25,8,15,7,12,20,9,14};
    int b,n=0;

    cin>>b;

    // linear searching
    for (int x:A) {
        if (x==b) {
            cout<<"Found element: "<<b<<endl;
            n=1;
            break;
        };
    };

    if (!n) {
        cout<<"not found";
    }

    return 0;
};
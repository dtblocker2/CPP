#include <iostream>

using namespace std;

int main() {
    int A[2][3] = {{2,3,4},{6,9,15}};
    cout<<A[1][2]<<endl;

    // use can use for loop but for forEach loop you need to give reference (&) to x in order to print y
    for (auto &x:A) {
        for (int y:x){
            cout<<y<<endl;
        };
    };

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int A[10] = {1,2,3,4,5};
    // it ive answer in byte storage use ie 1 int use 4 bytes so 10 int will use 40 bytes hence output is 40
    cout<<sizeof A<<endl; // 40

    //arrays size can't be changed even if variable is re-declared
    /* int A[5] = {1,2,3,4,5}; */ // error

    return 0;
}
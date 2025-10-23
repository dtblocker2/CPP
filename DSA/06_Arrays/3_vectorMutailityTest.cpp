#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = v1;
    v2.pop_back();

    // changing v2 does not change v2
    for (int x:v1) {
        cout<<x<<endl;
    };

    for (int x:v2) {
        cout<<x<<endl;
    };

    v2.push_back('H');
    // above action Automatically parse ch datatype of 'H' to int
    for (int x:v2) {
        cout<<x<<endl;
    };



    return 0;
};
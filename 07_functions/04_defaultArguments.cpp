#include <iostream>

using namespace std;

int add(int x, int y, int z=0) {
    return x+y+z; // by default if z value is not given then z is zero
}

int main() {

    cout<<add(12,14)<<endl; // int inputs

    return 0;
};

#include <iostream>

using namespace std;

int fun(int n) {
    // stopping condition
    if (n>5) {
        return 0;
    };
    cout<<n<<endl;

    // recursive part
    return fun(n+1);
};

int main() {
    fun(-10);

    return 0;
};
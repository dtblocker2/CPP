#include <iostream>

using namespace std;

// writing function for any datatype
/* 
t ==> template <class T>

T max(T x, Ty) {
    if (x>y) {
        return x;
    };

    return y;

}

*/

template<class T>
T maxim(T x, T y) {
    return x>y?x:y; // ternary function
}

int main() {

    cout<<maxim(12,14)<<endl; // int inputs
    cout<<maxim(1.2f,1.4f)<<endl; // float inputs
    cout<<maxim(1.2,1.4)<<endl; // double inputs

    // as we have use only one template ie T therfore datatype of both arguments must be same ir
    // cout<<maxim(12,1.4f)<<endl; // error
    return 0;
};

// find max pieces of lengths a, b or c we can make of l length rope? using recursion
#include <iostream>
using namespace std;

int maxPieces(int l, int a, int b, int c) {
    if (l==0) {
        return 0;
    };

    if (l<0) {
        return -1;
    };

    int resA = maxPieces(l-a,a,b,c);
    int resB = maxPieces(l-b,a,b,c);
    int resC = maxPieces(l-c,a,b,c);

    int res = max(resA, max(resB, resC));

    if(res == -1) return -1;
    return res+1;
};

int main() {
    cout<<maxPieces(23,12,14,11)<<endl;

    return 0;
};
#include <iostream>
#include <vector>
using namespace std;

/* vector<int> arr;

int jos(int n, int k, int z=0, int pos=0) {
    if (n==1) return arr[0];

    if (z==0)
    {
        for (int i=0; i<n; i++) {
            arr.push_back(i);
        };
    }

    for(int x:arr) {
        cout<<x;
    };
    cout<<endl;

    pos = (pos+k-1) % (arr.size());
    arr.erase(arr.begin() + pos);
    
    

    return jos(n-1, k, z+1, pos);
}; */

// teach's answer
int jos(int n, int k) {
    if (n==1) return 0;

    return (jos(n-1,k)+k)%n;
};

int main() {
    cout<<jos(5,3)<<endl;
    cout<<jos(8,2)<<endl;

    return 0;
};
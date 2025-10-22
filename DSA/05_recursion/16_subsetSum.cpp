#include <iostream>
using namespace std;

int countSum(int arr[], int n, int sum) {
    if (n==0) return (sum == 0) ? 1:0;

    return countSum(arr, n-1, sum) + countSum(arr, n-1, sum - arr[n-1]);
};

int main() {


    return 0;
};
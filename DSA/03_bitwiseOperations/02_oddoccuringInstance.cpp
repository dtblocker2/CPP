#include <iostream>
using namespace std;

// naive solution
namespace firstNaiveSolution
{
    int oddOccuringInstance(int arr[], int n)
    {
        for (int i=0; i<n; i++)
        {
            int count = 0;
            for (int j=0; j<n; j++)
            {
                if (arr[i]==arr[j])
                {
                    count++;
                };
            };
    
            if (count%2 != 0)
            {
                return arr[i];
            };
        };
        return 0;
    };
};

namespace secondEfficientSolution
{
    int oddOccuringInstance(int arr[], int n)
    {
        int output = 0;
        for (int i = 0; i < n; i++)
        {
            output ^= arr[i];
        }
        return output;
    };
};

// XOR gate propeties
/* 
x^x^....^x = 0 ==> x are even times
x^x^....^x = x ==> x are odd times

x^0 = x

there fore if we do
1^2^4^2^1^1^1^4^4 ==> 1^2^4^2^0^1^0 ==> 1^2^4^2^1 (XOR is commutative)
therefore
1^1^2^2^4 ==> 0^0^4 ==> 0^4 ==> 4

*/

int main()
{
    int a[] = {1,2,4,2,1,1,1,4,4};
    int m = 9;

    cout<< firstNaiveSolution::oddOccuringInstance(a,m)<<endl;
    cout<< secondEfficientSolution::oddOccuringInstance(a,m)<<endl;
};
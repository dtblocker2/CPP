#include <iostream>
using namespace std;

int main()
{
    int n, rev=0, temp;
    cin>>n;
    temp = n;

    // reversing n
    while (temp)
    {
        rev = rev*10 + temp%10;
        temp /= 10;
    };
    cout<<rev<<endl;

    if (rev == n)
    {
        cout<<"Yes it is palidrome"<<endl;
    }
    else
    {
        cout<<"No it is not palidrome"<<endl;
    };

    return 0;
};
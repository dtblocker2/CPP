#include <iostream>
using namespace std;

string countNoOfOnes(int n)
{
    int output=0;

    while (n)
    {
        n = n&(n-1);
        output += 1;
    };

    if (output==1)
    {
        return "Yes it is power of 2";
    };
    return "Not power of 2";
};

// or you can use
bool ispow2(int n)
{
    if (n==0)
    {
        return false;
    };

    return (n&(n-1)==0);
};

int main()
{
    for (int i=0; i<10; i++)
    {
        cout<<i<<": "<< countNoOfOnes(i) <<endl;
    };
    cout<<"lol"<<endl;
    cout<<"lol2"<<endl;

    return 0;
};
#include <iostream>
using namespace std;

int fact(int n)
{
    if (n<0)
    {
        throw "error number can't be negative";
    };

    if (n==0)
    {
        return 1;
    };

    return n*fact(n-1);
}

int main()
{
    /* int n, p=1;
    cin>>n;
    
    do
    {
        p *= n;
    }
    while (--n);

    cout<<p<<endl; */
    cout<<fact(6)<<endl;

    try
    {
        fact(-1);
    }
    catch(const char* e)
    {
        cout << e << endl;
    }
    

    return 0;
};
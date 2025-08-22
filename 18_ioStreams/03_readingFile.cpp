#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream infile;

    infile.open("my.txt");
    // what if file is not present so use
    if (!infile)
    {
        cout<<"file cannot be opened"<<endl;
    };

    // or use
    if (!(infile.is_open()))
    {
        cout<<"file cannot be opened"<<endl;
    };

    string str;
    int x;

    infile>>str;
    infile>>x;

    cout<<"str= "<<str<<" x= "<<x<<endl;

    if (infile.eof())
    {
        cout<<"end of file (eof) reached"<<endl;
        infile.close();
        cout<<"file closed"<<endl;
    };

    return 0;
};
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    // remember it will create file where output.exe is situated so be careful

    // below is dangerous if file is not present then it will create new file but if file is present then it will rewrite it/ truncate it
    ofstream outfile("02_my.txt", ios::trunc); 
    // by default it is truncate so you can remove trunc and use just ofstream outfile("02_my.txt");

    outfile<<"hello"<<endl;
    outfile<<25<<endl;
    outfile.close();

    // use ios::app to switch to append mode
    ofstream outfile2("02_my2.txt", ios::app);
    outfile2<<"hello"<<endl;
    outfile2<<25<<endl;
    outfile2.close();

    return 0;
};
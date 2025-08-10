#include <iostream>
#include <string>

using namespace std;

int main() {
    // declaration
    string str1;
    
    // size of string will not be equal to number of chr entered rather it will be slightly bigger

    // cin.getline wont be use rathe use getline(cin,str2)
    getline(cin,str1);

    cout<<"you entered: "<<str1<<endl;

    string str2 = "Hello world";

    // length of string
    cout<<str2.length()<<endl; // 11

    // size of string
    cout<<str2.size()<<endl; // 11

    // capacity of string
    cout<<str2.capacity()<<endl; // 15

    // resizing of string
    str2.resize(30);
    cout<<str2<<" "<<str2.capacity()<<endl; // 30

    // max_Size of string
    cout<<str2.max_size()<<endl; //   9223372036854775806

    // clearing of string
    str2.clear();
    cout<<str2<<endl;

    // check if string is empty
    cout<<str2.empty(); // 1 if true 0 if false

    return 0;
}

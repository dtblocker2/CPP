#include <string>
#include <iostream>

using namespace std;

int main() {
    // at() operator
    string str = "Holiday";
    cout<<str.at(4)<<endl; // d ==> char at index 4
    // you can also write too using at() operator
    str.at(4) = 'm';
    cout<<str<<endl;

    // front() and back() to get first and last char
    cout<<str.front()<<" "<<str.back()<<endl;

    // [] ==> same as at operator
    cout<<str[4]<<endl; // m ==> char at index 4
    // you can also write too using [] operator
    str.at(4) = 'd';
    cout<<str<<endl;

    // + ==> concating 2 strings
    string str2 = "Happy ";
    cout<<str2 + str<<endl;

    // = ==> assignment opereator
    str2 = "hi this can be editted with = operator";
    cout<<str2<<endl;

    return 0;
};

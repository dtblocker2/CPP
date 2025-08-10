#include <iostream>
#include <string>

using namespace std;

int main() {
    // dtring iterator ==> it
    // declaration
    string::iterator it; // use reverse_iterator for reverse direction

    string str = "hello world";
    // assignment
    /* for reverse_iterator use rbegin and rend */
    for (it=str.begin() ; it != str.end(); it++) {
        cout << *it<<endl; 
        *it = *it - 32;// covert ASCII code of lowercase to upper case
    };

    cout<<str<<endl;

    int k = '\0'; // to get value of ASCII code in int format
    cout<<k<<endl;

    // or we can use is
    // inplace of '\0' we can 0
    for (int i=0; str[i] != '\0';i++) {
        cout<<str[i]<<endl;
    };

    /* in above only
    H
    E
    L
    L
    O
    gets printed because due to blank space we get 0 in middle ie \0 operator 
    */

    return 0;
};

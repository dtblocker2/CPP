#include <iostream>
using namespace std;

int main() {
    char s1[20],s2[20];
    
    /* cin.get() vs cin.getline() */
    // cin.get()
    cout<<"Enter S1: ";
    cin.get(s1,20);
    // use cin.ignore after each cing.get()
    cin.ignore();
    
    cout<<"Enter S2: ";
    cin.get(s2,20); // s1 will be there but not s2
    cout<<s1<<" "<<s2<<endl;

    cin.ignore();

    // cin.getline()
    cout<<"Enter S1: ";
    cin.getline(s1,20);
    cout<<"Enter S2: ";
    cin.getline(s2,20); // s1 will be there but not s2
    cout<<s1<<" "<<s2<<endl;

    // if you use cin.getline() after calling cin.get() then it will not take inputs remember to clear buffer using cin.ignore()

    return 0;
}

#include <iostream>

int main()
{
    // declaring rollno variable
    unsigned int rollNo;

    // before we asigned value 10 to rollNo it would have a garbage value that we saw during visual studio debugger
    rollNo = 10; // now variable is initialized

    // declaring and initialising at same time to avoid garbage value
    int rollNo2 = 11;

    // char datatype is stored in '' and string is stored in ""
    char group = 'A';

    float price = 12.75f; // f is added to highlight its a float though it is not compulsory as if we don't write f it will consider it as double. though here we declared it is float but in some places by default decimal no. is consider as double unless we write f to make it float

    // naming rules for variables is just same as javascript and python

    return 0;
}

/* string can have 2000 charaqcters in it */

#include <iostream>
using namespace std;

int main() {
    // you can use character array or string class to store text

    // 1. char array
    char x = 'A';
    char S1[10] = "Hello"; // it is stored as {'H','e','l','l','o','\0',,,,} ==> here \0 is string delimiter or null character to define end of string
    char S2[] = "Hello"; // it is stored as {'H','e','l','l','o','\0'}
    char S3[] = {'H','e','l','l','o','\0','p','p','p'}; // ppp are ignored due to string delimiter \0
    char S4[] = {70,65,66,67,68,0,69,69,69,69,69}; //using ASCII notation in place of '\0] you can use 0 to use as string delimiter

    const char *S5 = "Hello"; // "Hello" is considered array of char only so we can make pointer *S and it it toward that array in heap just like we do new char[] instead we use double quotation mark
    // if you want string in stack use S[] to avoid memory leakage problem
    // const is used to make it read only and no rewrtable

    // at last you can use string class
    string S6 = "Hello";

    // use const or auto to make collection of strings
    const char* S[] = {S1,S2,S3,S4,S5}; // S6 is not char datatype so we cant stor it in here

    for (auto x:S) {
        cout<<x<<endl;
    };

    cout<<S6<<endl;

    return 0;
};
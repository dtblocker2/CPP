// preprocessors are instructions given to compiler before starting process of compilation
// AKA macros

// Define a constant
#define PI 3.145
#define c cout // defineing reference to other function
#define SQR(x) (x*x) //defining function
#define MSG(x) #x // converting x to string datatype

//if not define
#ifndef y
    #define y 10;
#endif
// ending if not define

// here PI is already defined so PI will not be 2
#ifndef PI
    #define PI 2;
#endif

#include <iostream>
using namespace std;

int main()
{
    cout<<PI<<endl;
    c<<3<<endl;
    cout<<SQR(5)<<endl;
    int x = 100;

    cout<<MSG(HEllo)<<endl; // see not using " " marks


    return 0;
};
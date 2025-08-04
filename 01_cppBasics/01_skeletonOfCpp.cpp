#include <iostream>
// iostream is library of some important function
// use <iostream.h> if your compiler doesn't support it

// below int before main is return function that returns value processed by function ie in this case is 0
int main()
{
    // body of code
    /* 
    printing in cpp is cout ie console out
    these << is called insertion operator

    std means namespace with scope resolution (::) operator then cout or cin
     */
    std::cout << "Hello World!";

    /* 
    cin is console input to take input from console
    notice >> is used ie 
    */
    int input;
    std::cin >> input;

    return 0;
};


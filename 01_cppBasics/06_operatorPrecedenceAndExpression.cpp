#include <iostream>
#include <math.h> // for mathematical functions

int main()
{
    // it is order in which operators will be executed kinda like BODMAS
    std::cout << 16/8*2; // mod, divide and multiply are given same importance so in line first divide is there so first division will occur then multiplication

    // similarly
    std::cout << 18%8*2;
    std::cout << 18*2%8; // first 18 *2 = 36 ==> 36 %8 = 4

    int z = sqrt(4); // from math.h module
    std::cout << z; // 2

    int x = pow(2,4);
    std::cout << x; // 16

    return 0;
}
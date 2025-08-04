// CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    /*std::cout << "Hello World!\n";
    char name[50];
	std::cout << "Enter your name: ";
    std::cin >> name;
	std::cout << "Hello, " << name << "!\n";
    function2();*/
    // adding breakpoint to run program till that line normally then debug at that point
    int sum = 0;
    int A[] = { 2,3,4,5,6,7 };
    for (int x : A)
    {
        sum = sum + x;
        std::cout << x << std::endl;
    };

    std::cout << "sum is:" << sum;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

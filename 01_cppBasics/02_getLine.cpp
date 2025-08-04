#include <iostream>
#include <string> // needed this library to get string as input

int main()
{
    // getting string datatype
    std::string name;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name); // to get whole line as input instead of just one word

    std::cout << "Your name is: " << name;
    // std::cin.get();

    return 0;
}

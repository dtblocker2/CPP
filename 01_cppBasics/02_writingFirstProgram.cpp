/* 
every program has three processes
1. taking input
2. processing it
3. giving output
*/

#include <iostream>

int main()
{
    std::cout << "Enter two numbers separated by space or either by new line too: ";
    
    // declare varibles before storing them
    int a, b;
    // input more than on variables
    std::cin >> a >> b;
    
    // declaring and assigning at same time
    int sum = a + b;
    std::cout << "Sum is: " << sum << std::endl;

    // Optional pause to keep console open
    std::cin.ignore(); // clear the newline
    std::cin.get();    // wait for key press

    return 0;
}

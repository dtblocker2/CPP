    #include <iostream>

    /* use
    g++ your_program.cpp -o your_program_name 
    
    to compile your program in executable file using g++ compiler
    
    to run exe file you can either run it directly by double clicking it using gui but you will need to use std::cin.get() to pause to read output

    or use can use ./fileName.exe directly on git bash or powershell to run the exe file inside terminal easily

    without need to use debug option
    */

    int main() {
        // endl means \n of string
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.get(); // Waits for user to press Enter
        std::cout << "Continuing program execution." << std::endl;
        return 0;
    }
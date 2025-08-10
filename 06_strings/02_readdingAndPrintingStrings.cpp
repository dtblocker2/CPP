#include <iostream>
#include <limits> // <-- Needed for numeric_limits
using namespace std;

int main() {
    char name[20]; // '\0' is included so total 19 letters are allowed

    cout << "Enter Your name: ";
    cin >> name; // cin stops at first space
    cout << "Your name is: " << name << endl;

    // Clear leftover characters from the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char c[50], c2[50];
    cout << "Enter your name again: ";
    cin.get(c, 50); // reads until newline or 49 chars
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline

    cout << "Enter your surname: ";
    cin.getline(c2, 50);

    cout << "Your new name is: " << c << " And: " << c2 << endl;

    return 0;
}

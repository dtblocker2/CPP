#include <iostream>
#include <iomanip>  // For manipulators
using namespace std;

int main() {
    int num = 255;
    double pi = 3.141592653589793;

    cout << "Integer output formats:\n";

    // Decimal (default)
    cout << "Decimal: " << dec << num << endl;

    // Hexadecimal
    cout << "Hexadecimal: " << hex << num << endl;

    // Octal
    cout << "Octal: " << oct << num << endl;

    // Back to decimal
    cout << "Back to decimal: " << dec << num << endl;

    cout << "\nFloating-point output formats:\n";

    // Default floating point representation
    cout << "Default: " << pi << endl;

    // Fixed-point notation with precision 4
    cout << fixed << setprecision(4);
    cout << "Fixed (4 decimals): " << pi << endl;

    // Scientific notation with precision 4
    cout << scientific << setprecision(4);
    cout << "Scientific (4 decimals): " << pi << endl;

    // Back to default formatting
    cout.unsetf(ios::fixed | ios::scientific);
    cout << "Default again: " << pi << endl;

    cout << "\nText alignment and width manipulators:\n";

    cout << left << setw(10) << "Left" << "|" << right << setw(10) << "Right" << "|" << endl;

    // Demonstrating setw with numbers
    cout << left << setw(10) << 123 << "|" << right << setw(10) << 456 << "|" << endl;

    // Using ws manipulator to consume whitespace before input (example)
    cout << "\nEnter some text with leading spaces: ";
    string input;
    cin >> ws;  // consume leading whitespaces
    getline(cin, input);
    cout << "You entered: '" << input << "'" << endl;

    return 0;
}

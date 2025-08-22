#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    // The exact bytes for "Hello, World!\n"
    const char hello[] = {
        0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20,
        0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x0A
    };

    ofstream outfile("02_my2.txt", ios::binary);
    if (!outfile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    // Write the bytes directly
    outfile.write(hello, sizeof(hello));
    outfile.close();

    cout << "Binary data written to 02_my2.txt" << endl;
    return 0;
}

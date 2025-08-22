#include <iostream>
#include <fstream>
using namespace std;

class FileHandler {
private:
    fstream file;

public:
    // Constructor: open the file
    FileHandler(const string& filename) {
        file.open(filename, ios::in | ios::out | ios::app);
        if (file.is_open()) {
            cout << "File opened successfully." << endl;
        } else {
            cout << "Failed to open file." << endl;
        }
    }

    // Function to write data to the file
    void write(const string& data) {
        if (file.is_open()) {
            file << data << endl;
        } else {
            cout << "File not open for writing." << endl;
        }
    }

    // Destructor: close the file when object goes out of scope
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            cout << "File closed automatically in destructor." << endl;
        }
    }
};

int main() {
    {
        FileHandler fh("example.txt");
        fh.write("Hello, this is a test line.");
    } // Destructor called here, file closed automatically

    cout << "End of main." << endl;
    return 0;
}

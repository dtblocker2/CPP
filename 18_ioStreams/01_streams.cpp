#include <iostream>
#include <fstream>
#include <iomanip>  // For manipulators like setprecision, setw
using namespace std;

int main() {
    // 1. Standard Output (cout) - Writing to console
    cout << "Standard Output Stream (cout) Example" << endl;
    int num = 42;
    cout << "The number is: " << num << endl;

    // 2. Standard Input (cin) - Reading from console
    cout << "\nEnter your age: ";
    int age;
    cin >> age;
    cout << "You entered age: " << age << endl;

    // Check for input error
    if (!cin) {
        cout << "Input error detected!" << endl;
        cin.clear(); // Clear error state
        cin.ignore(1000, '\n'); // Ignore bad input
    }

    // 3. File Output (ofstream) - Writing to file
    ofstream outFile("sample.txt");
    if (outFile.is_open()) {
        outFile << "Writing to a file using ofstream." << endl;
        outFile << "Number: " << num << ", Age: " << age << endl;
        outFile.close();
        cout << "\nData written to file successfully." << endl;
    } else {
        cout << "Could not open file for writing!" << endl;
    }

    // 4. File Input (ifstream) - Reading from file
    ifstream inFile("sample.txt");
    cout << "\nReading from file:" << endl;
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Could not open file for reading!" << endl;
    }

    // 5. Stream manipulators for formatting output
    double pi = 3.1415926535;
    cout << "\nFormatted output using manipulators:" << endl;
    cout << fixed << setprecision(3); // Fixed point, 3 decimal places
    cout << "Pi rounded to 3 decimals: " << pi << endl;

    int number = 255;
    cout << hex << number << " in hexadecimal" << endl; // Hexadecimal output
    cout << dec; // Switch back to decimal

    // 6. Stream state check example
    cout << "\nEnter an integer: ";
    int value;
    cin >> value;
    if (cin.fail()) {
        cout << "Error: Invalid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } else {
        cout << "You entered: " << value << endl;
    }

    return 0;
}


/* Here is a detailed explanation of the **streams concept** in C++ with illustrative code examples:

***

# C++ Streams Concept Explained

**Streams** in C++ represent a flow of data that can be read from or written to devices like the console, files, or memory. They provide a high-level, flexible interface for input/output operations.

***

## 1. What is a Stream?

- A stream is a continuous flow of bytes (characters) for data transfer.
- It abstracts input and output devices into a uniform interface.
- Types of streams:
  - **Input stream (istream):** For reading data (e.g., `cin`).
  - **Output stream (ostream):** For writing data (e.g., `cout`).
  - **File streams (ifstream, ofstream, fstream):** For reading/writing files.
  
***

## 2. Standard Streams

| Stream | Description                |
|--------|----------------------------|
| `std::cin`   | Standard input stream (keyboard)  |
| `std::cout`  | Standard output stream (console)  |
| `std::cerr`  | Standard error stream (console)   |
| `std::clog`  | Standard logging stream (console) |

***

## 3. Using Output Streams (`ostream`)

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl; // Output text followed by newline
    int x = 10;
    cout << "Value of x is: " << x << endl;
    return 0;
}
```

- `<<` is the insertion operator used to send data to streams.
- Supports chaining, e.g., `cout << "a = " << a << ", b = " << b << endl;`

***

## 4. Using Input Streams (`istream`)

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;    // Extracts input from standard input
    cout << "You entered: " << age << endl;
    return 0;
}
```

- `>>` is the extraction operator used to read formatted input from streams.
- Extracts input and converts it to the specified variable's type.

***

## 5. File Streams (`ifstream`, `ofstream`, `fstream`)

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Writing to a file
    ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Writing this to a file.\n";
        outFile.close();
    }

    // Reading from a file
    ifstream inFile("example.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    return 0;
}
```

- `ofstream` is for output (writing to files).
- `ifstream` is for input (reading from files).
- `fstream` supports both input and output.
- Use `.open()` and `.close()` for file control or constructor/destructor automatically manage files.

***

## 6. Stream States and Error Handling

Streams have error state flags:

| Flag           | Meaning                            |
|----------------|----------------------------------|
| `goodbit`      | Stream is fine                   |
| `eofbit`       | End of file encountered          |
| `failbit`      | Input/output operation failed    |
| `badbit`       | Non-recoverable error occurred   |

Check stream state:

```cpp
if (!cin) {
    cout << "Input error!" << endl;
}
```

***

## 7. Manipulators

Functions that modify stream behavior, for example:

```cpp
#include <iostream>
#include <iomanip> // for manipulators
using namespace std;

int main() {
    double pi = 3.1415926535;

    cout << fixed << setprecision(2); // fixed-point notation, 2 decimals
    cout << "Pi = " << pi << endl;

    cout << hex << 255 << endl; // prints 255 in hexadecimal (ff)
    return 0;
}
```

***

# Summary

| Concept                  | Example          | Notes                            |
|--------------------------|------------------|---------------------------------|
| Standard output stream   | `cout`           | Writes to console                |
| Standard input stream    | `cin`            | Reads from console              |
| File output stream       | `ofstream`       | Writes to files                 |
| File input stream        | `ifstream`       | Reads from files                |
| Stream state flags       | `eofbit`, `failbit` | For error handling             |
| Manipulators             | `endl`, `setw`   | For formatting output           |

Streams provide a powerful, flexible mechanism to manage input/output in C++ across devices and data sources.

***

If you want, I can provide code examples for specific stream operations or advanced usage like custom stream buffers! */
#include <iostream>
using namespace std;

int main() {
    // Initial size of dynamic array
    int size = 10;

    // Create a dynamic array of size 'size'
    int *p = new int[size];

    // sizeof(*p) = size of one int (likely 4 bytes)
    cout << "Size of one element: " << sizeof(*p) << " bytes" << endl;
    cout << "Number of elements: " << size << endl;

    // Fill the array with some values
    for (int i = 0; i < size; i++) {
        p[i] = i * 10; // example values
    }

    // Print the values
    cout << "\nOriginal array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "p[" << i << "] = " << p[i] << endl;
    }

    // --- Resize array ---
    int newSize = 40;

    // Always delete the old memory before assigning new memory
    delete[] p;  
    p = new int[newSize]; // Create bigger array

    // Assign some values to the new array
    for (int i = 0; i < newSize; i++) {
        p[i] = i + 100; // example values
    }

    // Example: set specific values
    p[30] = 10;
    p[31] = 200;

    // Print the new values
    cout << "\nResized array:" << endl;
    for (int i = 0; i < newSize; i++) {
        cout << "p[" << i << "] = " << p[i] << endl;
    }

    // Free the memory when no longer needed
    delete[] p;
    p = nullptr; // Avoid dangling pointer

    return 0;
}

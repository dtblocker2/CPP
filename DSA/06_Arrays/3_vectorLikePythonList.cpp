#include <iostream>
#include <vector>
#include <string>
#include <any>    // Required for std::any
#include <typeinfo> // Required for typeid

using namespace std;

int main() {
    // Create a vector that can hold 'any' type
    vector<any> mixed_list;

    // Now you can add different types, just like in Python!
    mixed_list.push_back(10);             // An integer
    mixed_list.push_back("Hello");        // A string literal (const char*)
    mixed_list.push_back(string("World")); // An std::string object
    mixed_list.push_back(3.14159);        // A double

    // --- Individual casting (your original, correct code) ---
    cout << "--- Printing individual items by casting ---" << endl;
    
    // Get the first item (index 0) and cast it to an int
    int my_int = std::any_cast<int>(mixed_list[0]);
    cout << "Item 0: " << my_int << endl;

    // Get the third item (index 2) and cast it to a string
    string my_string = std::any_cast<string>(mixed_list[2]);
    cout << "Item 2: " << my_string << endl;

    // Get the fourth item (index 3) and cast it to a double
    double my_double = std::any_cast<double>(mixed_list[3]);
    cout << "Item 3: " << my_double << endl;

    // --- THIS IS THE CORRECT WAY TO LOOP ---
    // You must check the type of 'item' in each iteration
    
    cout << "\n--- Printing all items with a safe loop ---" << endl;
    int i = 0;
    for (const auto& item : mixed_list) {
        cout << "Item " << i++ << ": ";

        // Check the type stored inside the 'any'
        // We use .type() and compare it with typeid()
        if (item.type() == typeid(int)) {
            cout << std::any_cast<int>(item) << " (is an int)" << endl;
        } 
        else if (item.type() == typeid(const char*)) {
            // This handles item 1 ("Hello")
            cout << std::any_cast<const char*>(item) << " (is a const char*)" << endl;
        }
        else if (item.type() == typeid(string)) {
            // This handles item 2 (string("World"))
            cout << std::any_cast<string>(item) << " (is a std::string)" << endl;
        }
        else if (item.type() == typeid(double)) {
            cout << std::any_cast<double>(item) << " (is a double)" << endl;
        }
        else {
            cout << "Unknown type!" << endl;
        }
    }

    // Your original loops (which don't work) have been removed.

    return 0;
}
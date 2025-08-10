#include <iostream>
#include <string>
using namespace std;

int main() {
    // Starting string
    string str = "Hello";

    // 1️⃣ append() → Add string at the end
    str.append(" World");
    cout << "append: " << str << endl; // Hello World

    // 2️⃣ insert(pos, str) → Insert at given position
    str.insert(5, ",");
    cout << "insert: " << str << endl; // Hello, World
    str.insert(5, "Hi there",4);
    cout << "insert: " << str << endl; // insert only first 4 worlds og "hi there"

    // 3️⃣ replace(pos, len, str) → Replace part of string
    str.replace(7, 5, "C++");
    cout << "replace: " << str << endl; // Hello, C++
    // replace from index 7 and replace 5 letter from it

    // 4️⃣ erase(pos, len) → Remove part of string
    str.erase(5, 2); // removes "Hi"
    cout << "erase: " << str << endl; // HelloC++

    // 5️⃣ push_back(char) → Add single character at end
    str.push_back('!');
    cout << "push_back: " << str << endl; // HelloC++!

    // 6️⃣ pop_back() → Remove last character
    str.pop_back();
    cout << "pop_back: " << str << endl; // HelloC++

    // 7️⃣ swap() → Swap with another string
    string other = "Programming";
    str.swap(other);
    cout << "swap: str=" << str << ", other=" << other << endl;

    return 0;
}

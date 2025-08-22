#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

int main() {
    // Vector and iterator
    vector<int> v = {10, 20, 30, 40};
    cout << "Vector elements using iterator: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Modifying values via iterator
    for (auto it = v.begin(); it != v.end(); ++it) {
        *it += 5;  // increment each element by 5
    }
    cout << "Modified vector: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // List and iterator
    list<string> lst = {"apple", "banana", "cherry"};
    cout << "List elements: ";
    for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Removing an element using iterator
    for (auto it = lst.begin(); it != lst.end(); ) {
        if (*it == "banana")
            it = lst.erase(it); // erase returns iterator to next element
        else
            ++it;
    }
    cout << "List after removal: ";
    for (const auto& s : lst) cout << s << " ";
    cout << "\n\n";

    // Set and const_iterator (iterators to set elements are const)
    set<int> s = {3, 1, 4, 1, 5};
    cout << "Set elements (sorted, unique): ";
    for (set<int>::const_iterator it = s.cbegin(); it != s.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iterator example for vector
    cout << "Vector elements in reverse: ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << "\n";

    return 0;
}

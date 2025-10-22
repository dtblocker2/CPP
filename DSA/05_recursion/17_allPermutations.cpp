#include <iostream>
using namespace std;

void allPermutations(string s, int n, string output="") {
    // Base case: if all characters are used, print the result
    if (n == 0) {
        cout << output << endl;
        return;
    }
    
    for (int i = 0; i < s.length(); i++) {
        // Choose a character, exclude it from the remaining string and recurse
        string remaining = s.substr(0, i) + s.substr(i + 1);
        allPermutations(remaining, n - 1, output + s[i]);
    }
}

int main() {
    allPermutations("ABCD", 4);  // This will generate all permutations of "ABC"
    return 0;
}

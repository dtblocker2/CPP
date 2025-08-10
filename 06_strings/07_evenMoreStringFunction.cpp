#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello World";
    string s2 = "World";
    string s3;

    // copy() - copies characters into a char array
    char buffer[20];
    size_t copied = s1.copy(buffer, 5, 0); // copy first 5 chars from s1 into buffer
    buffer[copied] = '\0'; // null-terminate
    cout << "Copied characters: " << buffer << endl;

    // find() - find first occurrence of substring
    size_t pos = s1.find(s2);
    if (pos != string::npos)
        cout << "Found '" << s2 << "' at position: " << pos << endl;
    else
        cout << "Not found!" << endl;

    // rfind() - find last occurrence of substring
    size_t lastPos = s1.rfind("l");
    if (lastPos != string::npos)
        cout << "Last 'l' found at position: " << lastPos << endl;

    // find_first_of() - find first occurrence of any char from given set
    size_t firstVowel = s1.find_first_of("aeiou");
    int firstVowel2 = s1.find_first_of("aeiou");;
    if (firstVowel != string::npos)
        cout << "First vowel at position: " << firstVowel << " that is " << s1[firstVowel2] << endl;

    // find_last_of() - find last occurrence of any char from given set
    size_t lastVowel = s1.find_last_of("aeiou");
    if (lastVowel != string::npos)
        cout << "Last vowel at position: " << lastVowel << endl;

    // substr() - get substring
    string sub = s1.substr(6, 5); // start at index 6, length 5
    cout << "Substring: " << sub << endl;

    // compare() - lexicographical comparison
    s3 = "Hello";
    if (s1.compare(s3) == 0)
        cout << "Strings are equal" << endl;
    else if (s1.compare(s3) > 0)
        cout << "s1 is greater than s3" << endl;
    else
        cout << "s1 is smaller than s3" << endl;

    return 0;
}

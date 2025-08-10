#include <iostream>
#include <cstring> // For strlen, strcat, strcpy, strncpy
using namespace std;

int main() {
    char str1[] = "dtblocker";
    const char *str2 = "goku"; 

    // length of string
    cout << strlen(str1) << endl; // 9
    cout << strlen(str2) << endl; // 4

    // Make destination large enough for concatenation
    char a[50] = "Good";
    char b[] = "morning";

    // strcat(destination, source)
    strcat(a, b); 
    cout << "After strcat: " << a << endl;

    // Reset a for next example
    strcpy(a, "Good");

    // strncat(destination, source, n)
    strncat(a, b, 5); // adds only first 5 chars of b
    cout << "After strncat (5 chars): " << a << endl;

    // strcpy(destination, source)
    strcpy(a, b);
    cout << "After strcpy: " << a << endl;

    // strncpy(destination, source, n)
    strncpy(a, b, 3);
    a[3] = '\0'; // Ensure null termination
    cout << "After strncpy (3 chars): " << a << endl;

    // strstr(strign,substring) find subtring in string if it is present in str or not
    char m[] = "hello world";
    cout << strstr(m,"l") << endl; // if true return substring after starting of that substring else blank ==> "llo world"

    // strchr(strign,substring) find character in string if it is present in str or not
    cout << strchr(m,'l') << endl; // if true return substring after starting of that character else blank ==> "llo world"

    // strrchr(strign,substring) find character in string if it is present in str or not in reverse direction
    cout << strrchr(m,'l') << endl; // if true return substring after starting of that character else blank/NULL ==> "ld"

    // string compare: strcmp(str1,str2)
    char q[] = "lol", p[] = "lolQ";
    cout << strcmp(q,p) << " " << strcmp(p,q)<<" ";

    char q2[] = "Lol", p2[] = "lol";
    cout << strcmp(q2,p2)<<endl; // here q2 is has capital L so it will have more weight to it hence answer is -1 if their sum were equal then they would have been 0

    /* 
    -1 ==> q is less than p
    0 ==> if q has sum of char more than p
    1 ==> if p has more letters
     */

    // convert string into number
    char k[] = "1234";
    int g = strtol(k,NULL,5); // str to l means string to long int
    // strol(str, ending parameter, base of number system used)
    char k2[] = "12.32";
    float fl = strtof(k2,NULL); // str to f means string to float

    cout<<g<<" "<<fl+1.9<<endl; // g prints as 194 because it converts to decimel on printing hence decimal of 1234 in base 5 is 194

    // string tokenizer ==> strtok(str, separator_substring)
    char str3[] = "x=10;y=20;z=30";
    char *token = strtok(str3,"=;"); // tokenization is done on both = and ; sign

    while (token!=NULL) {
        cout <<token<<endl;
        token = strtok(NULL,"=;");
    };

    return 0;
}

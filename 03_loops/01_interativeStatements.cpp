/* 
1. While
2. Do while 
3. For
4. ForEach
they are just like javascript
*/

#include <iostream>

using namespace std;

int main() {
    long long int i = 0;

    while (i<1001) {
        i++;
    };

    for (int j = 0; j<10; j++) {
        cout << j << endl;
    };

    int n = 0;
    do {
    cout << n << "\n";
    n++;
    } while (n < 5);


    return 0;
};

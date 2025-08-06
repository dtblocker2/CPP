#include <iostream>

using namespace std;

int main() {
    int i;

    cin >> i;

    switch (i) {
        case (0): 
            cout << 0;
            // here there is no break so next case will also get executed ==> this process is called fall through
        case (1):
            cout << 1;
            break;
        
        case (2):
            cout << 2;
            break;
        
        case (3):
            cout << 3;
            break;
        
        default:
            cout << "This is default case and it will always run if cases are not matched";
            break;
    };

    return 0;
};

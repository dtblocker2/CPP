#include <iostream>

using namespace std;

int main() {
    /* for variable declared in block of if else statement the memory assigned to them is revoked after block is ended it memory is cleared after they are no longer required. No need to clear memory/ release memory by unused variables again and again.
    in c it was not case of c as we need to declare all variables at start of code and clear them after they become useless  */

    if (1==1) {
        int m = 10;
        cout << m << endl;
    };

    // cout << m << endl; // error

    // let us assume we need a variable for short amount of time just to compare value in if elese statement so what we can do is

    /* if (int k = 100; k < 200 ) {
        cout << k;
    }; */
    
    // cout << k; // error

    // lly we do for for command 
    for (int i = 0; i<5; i++) {
        cout << i << endl;
    }

    // cout << i; //error

    return 0;
};

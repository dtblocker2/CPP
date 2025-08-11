#include <iostream>

using namespace std;

int min(int a, int b) {
    return a<b?a:b;
};

int max(int a, int b) {
    return b<a?a:b;
};

int main() {
    
    // defining pointer to function
    int (*fp) (int, int);

    fp = max; // now fp becomes max function
    cout<<(*fp)(10,5)<<endl;

    fp = min; // now fp becomes min function
    cout<<(*fp)(10,5)<<endl;

    /* this is called runtime polymorphism */

    return 0;
};
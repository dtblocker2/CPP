#include <iostream>

using namespace std;

/* using function with same name but different parameters ie different datatypes or number of parameters */

int add(int w, int x, int y) {
    int z;
    z=x+y+w;
    
    return z;
};

// its actually subtract to see which will be executed
int add(int x, int y) {
    int z;
    z=x-y;

    return z;
};

float add(float x, float y) {
    float z;
    z=x*y;

    return z;
};

int main() {
    int a=2,b=3,c=4;
    float d=4.5f,e=4.0f;

    cout<<add(a,b)<<endl;
    cout<<add(a,b,c)<<endl;
    cout<<add(e,d)<<endl;

    return 0;
};

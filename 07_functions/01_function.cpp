#include <iostream>

using namespace std;

/* 
return_type function_name( parameter_list ) {

    return atmost_1_value
}

use void top return none type parameter
*/

void display() {
    string name;
    cout<<"Enter Your Name: ";
    cin>>name;
    cout<<"Hello "<<name<<endl;
};

int add(int x, int y) {
    int z;
    z=x+y;

    return z;
};

int main() {
    display();

    int a=1,b=2,c;

    c = add(a,b);

    /* here we know a,b and c are created in stack and x,y and z are also created in stack during function run after function execution is completed a,y,z all three are cleared automatically
    some of function memory may go to heap which has to be released */

    
    return 0;
};

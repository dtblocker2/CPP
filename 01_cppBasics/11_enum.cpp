#include <iostream>

using namespace std;

enum day { mon,tue,wed=5,thu,fri,sat=10,sun }; //use mon and not "mon" ie don't use string as string module is not imported
enum dept { cs=1,ee=10,ce=9,me };

int main() {
    day d; //defining custom variable
    d = mon;
    cout << d <<endl; // 0  because index of mon is 0 in day object

    dept n;
    n = ee;
    cout << n << endl; // 2 because cs=1 so index of ee is 2
    
    int k;
    k = d+1; // we can use d as integer for other int datatype
    cout << k << endl;

    // but we can't use it as int for itself

    // error because on adding day and int it returns int datatype but we have defined d as day datatype so we need to type cast it otherwise it won't compile
/*     d = d + 1;
    cout << d << endl; 
 */
    cout << cs << endl;
    cout << ee << endl;
    cout << me << endl;
    cout << ce << endl;


    return 0;
};

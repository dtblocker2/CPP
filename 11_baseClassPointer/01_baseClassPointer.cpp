#include <iostream>

using namespace std;

class Base {
    private:
    int z=5;

    protected:
    int w=15;

    public:
    int x = 10;

};

class Derived:public Base {
    public:
    int y=20;
};

int main() {
    // base class pointer can point to derived class object
    Base *p;
    p = new Derived();

    // but we can not use derived class object for base class
/*     Derived *q;
    q = new Base(); */

    // we can use all base class variables
    cout<<p->x<<endl;

    // though we can use base class ponter for derived clas but still we cannot access derived class attributes
    // cout<<p->y<<endl; // error

    return 0;
};
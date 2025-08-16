// inner classes of outer can can only access static members of outer class and not other members;

#include <iostream>
using namespace std;

class Outer{
    public:
    int a=10;
    static int b;

    // i object of inner class can be accessesed anywhere in outer class
    void fun() {
        i.show();
        cout<<i.x<<endl;
    };

    // inner class
    class Inner {
        public:
        int x=25;

        void show() {
            cout<<b<<endl; //static variable can be shown

            // cout<<a<<endl; // error normal members are not accessible to inner classes
        };
    };

    // outer class can create object of inner class note==> inner class object must be defined after inner class is defined
    Inner i;
};

int Outer::b =0;

int main() {
    Outer o;
    o.fun();

    // you can also use below notation to create object of inner class if you don't want inner class to be used outside outer class just put inner class in private member
    Outer::Inner i;
    i.show();

    return 0;
};
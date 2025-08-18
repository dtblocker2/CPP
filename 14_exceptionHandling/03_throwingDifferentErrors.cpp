#include <iostream>

using namespace std;

class Base {
    public:
    Base() {
        cout<<"Default constructor of Base class"<<endl;
    };

    Base(int x) {
        cout<<"Parameterize constructor of Base class "<<x<<endl;
    };
};

class Derived:public Base {
    public:
    Derived() {
        cout<<"Default constructor of Derived class"<<endl;
    };

    Derived(int x) {
        cout<<"Parameterize constructor of Derived class "<<x<<endl;
    };

    Derived(int x, int a):Base(x) {
        cout<<"Parameterize constructor of Derived class "<<a<<endl;
    };
};

int main()
{
    try
    {
        // throw 1.5; // to execute double catch 
        // throw 'A'; // to execute all catch
        throw Derived(10);
    }
    catch (int e)
    {
        cout<<"Integer is caught "<<e<<endl;
    }
    catch (double e)
    {
        cout<<"double is caught "<<e<<endl;
    }
    // make sure drived/child classes must be caught before because if catch of parent class is written before then it will catch errors of derived class
    catch (Derived e)
    {
        cout<<"derived class error caught"<<endl;
    }
    catch (Base e)
    {
        cout<<"derived Base error caught"<<endl;
    }
    catch (...) // to catch any datatype error that is not present previously
    {
        cout<<"All catch is executed"<<endl;
    }

    return 0;
};
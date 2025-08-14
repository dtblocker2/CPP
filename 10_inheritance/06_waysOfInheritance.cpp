/* ways of inheritence:
1. public ==> public class of base becomes public of derived class and protected of base class become protected of derived class and private of base class is not inherited

2. protected ==> both public and protected of base class become protected of derived class and privat of base class is not inherited

3. private ==> both public and protected of base class become private of derived class and private of base class is not inherited
*/

#include <iostream>
using namespace std;

class Base {
public:
    int pubVar;       // Accessible anywhere
protected:
    int protVar;      // Accessible in Base and its derived classes
private:
    int privVar;      // Accessible only in Base

public:
    Base() : pubVar(1), protVar(2), privVar(3) {}

    void showBase() {
        cout << "Base: pubVar=" << pubVar
             << ", protVar=" << protVar
             << ", privVar=" << privVar << endl;
    }
};

// PUBLIC inheritance: public stays public, protected stays protected
class PublicDerived : public Base {
public:
    void accessMembers() {
        cout << "\n[Public Inheritance]" << endl;
        cout << "pubVar = " << pubVar << endl;     // OK
        cout << "protVar = " << protVar << endl;   // OK
        // cout << privVar;  // ❌ Not accessible
    }
};

// PROTECTED inheritance: public & protected become protected
class ProtectedDerived : protected Base {
public:
    void accessMembers() {
        cout << "\n[Protected Inheritance]" << endl;
        cout << "pubVar = " << pubVar << endl;     // OK (now protected)
        cout << "protVar = " << protVar << endl;   // OK
        // cout << privVar;  // ❌ Not accessible
    }
};

// PRIVATE inheritance: public & protected become private
class PrivateDerived : private Base {
public:
    void accessMembers() {
        cout << "\n[Private Inheritance]" << endl;
        cout << "pubVar = " << pubVar << endl;     // OK (now private)
        cout << "protVar = " << protVar << endl;   // OK
        // cout << privVar;  // ❌ Not accessible
    }
};

int main() {
    Base b;
    b.pubVar = 10; // ✅ Public in Base
    // b.protVar = 20; // ❌ Protected - not accessible here
    // b.privVar = 30; // ❌ Private - not accessible

    b.showBase();

    PublicDerived pd;
    pd.accessMembers();
    pd.pubVar = 50; // ✅ Still public due to public inheritance

    ProtectedDerived prd;
    prd.accessMembers();
    // prd.pubVar = 60; // ❌ Now protected, can't access from main

    PrivateDerived pvd;
    pvd.accessMembers();
    // pvd.pubVar = 70; // ❌ Now private, can't access from main

    return 0;
}

/* 
| **Inheritance Type** | **Base Public →** | **Base Protected →** | **Base Private →** |
| -------------------- | ----------------- | -------------------- | ------------------ |
| **Public**           | Public            | Protected            | Not Inherited      |
| **Protected**        | Protected         | Protected            | Not Inherited      |
| **Private**          | Private           | Private              | Not Inherited      |


*/
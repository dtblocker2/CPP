#include <iostream>
using namespace std;

class Demo {
private:
    int* ptr;

public:
    // Constructor: allocate memory
    Demo(int size) {
        ptr = new int[size];
        cout << "Constructor called, memory allocated." << endl;
    }

    // Destructor: free memory
    ~Demo() {
        delete[] ptr;
        cout << "Destructor called, memory freed." << endl;
    }

    void display() {
        cout << "Demo class object." << endl;
    }
};

int main() {
    {
        Demo d(5);  // Constructor runs here
        d.display();
    } // Destructor automatically runs here as d goes out of scope

    cout<<"making new d2"<<endl;
    Demo *d2 = new Demo(4);
    delete d2; // to delete d2 pointer that used heap memory and hence destrucotr will be called

    cout << "End of main." << endl;
    return 0;
}

// destructors can not be overloaded but it can be virtual
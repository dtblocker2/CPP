#include <iostream>

using namespace std;

// here Car is 'Abstract Class' ie class that only has pure virtual function ==> AKA Interface ==> serves as layout for other child classes
class Car {
    public:
    // here these are 'Pure Virtual Functions' ==> they are only made to be overwritten and have no self use
    virtual void start() = 0;
    virtual void stop() = 0;
};

class Swift:public Car {
    public:
    void start() {
        cout<<"Swift Started"<<endl;
    };

    void stop() {
        cout<<"Swift stopped"<<endl;
    };
};

class Innova:public Car {
    public:
    void start() {
        cout<<"Innova Started"<<endl;
    };

    void stop() {
        cout<<"Innova stopped"<<endl;
    };
};

int main() {
    Car *c = new Innova();
    c->start();

    c = new Swift();
    c->start();

    return 0;
};
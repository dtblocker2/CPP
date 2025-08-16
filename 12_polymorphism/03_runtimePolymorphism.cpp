#include <iostream>

using namespace std;

class Car {
    public:
    virtual void start() {
        cout<<"Car Started"<<endl;
    };

    virtual void stop() {
        cout<<"Car stopped"<<endl;
    };
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
    // if we have separate start for both innova and swift then what is point of having parent car class?
    // see below
    Car *c = new Innova();
    c->start(); // innova starts given we have virtual function

    c = new Swift();
    c->start(); // swift starts

    return 0;
};
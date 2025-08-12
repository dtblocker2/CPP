#include <iostream>

using namespace std;

class Account {
    private:
        float balance=0;

    public:
        string name;

        // we can access balance only by deposit and withdrawn and show balance w can directly edit balance
        void deposit(float amount) {
            balance += amount;
        };

        void withdraw(float amount) {
            int x = balance - amount;

            if (x<0) {
                cout<<"Balance can't be negative"<<endl;
                return;
            };

            balance = x;
        };

        void show_name() {
            cout<<name<<endl;
        };

        void show_balance() {
            cout<<balance<<endl;
        };

        /* 
        here show_balance ==> acts as accessor

        withdraw and deposit functions act as ==> mutator
        */
};

int main() {
    Account a1;
    a1.name = "dtblocker";
    a1.show_balance();

    a1.deposit(1000);
    a1.show_balance();

    a1.withdraw(600);
    a1.show_balance();

    // a1.balance += 1000000000; // error ==> balance is private so can't access directly

    // can directly read value of balance
    // cout<<a1.balance<<endl;

    a1.withdraw(1000);
    a1.show_balance();

    return 0;
};
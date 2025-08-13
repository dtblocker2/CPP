#include <iostream>

using namespace std;

class Complex {
    private:
        float real;
        float img;

    public:
        Complex (float real=0, float img=0) {
            this->real = real;
            this->img = img;
        };

        // use operator overloading to add only 2 functions
        /* Complex operator+(Complex x) {
            Complex temp;
            temp.real = this->real + x.real;
            temp.img = this->img + x.img;

            return temp;
        }; */

        // use friend function to chain + operator function 

        friend Complex operator+(Complex c1, Complex c2);

        friend ostream& operator<<(ostream &o, const Complex &c) {
            o << c.real << " + " << c.img << "i";
            return cout;
        };
};

Complex operator+(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;

    return temp;
};

int main() {
    Complex C1(1,2);
    cout<<C1<<endl;

    Complex C2(2,2);
    cout<<C2<<endl;

    Complex C3 = C1 + C2;
    cout<<C3<<endl;

    cout<<C1+C2+C3<<endl;

    return 0;
};
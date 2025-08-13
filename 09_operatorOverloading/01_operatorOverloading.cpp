#include <iostream>

using namespace std;
/* overloading operator ==> using classic operator symbols like +,-,/ etc. for custom class operator

eg using + for matrix class to perform matrix addition
*/

// example complex number

class Complex {
    private:
        float real;
        float img;

    public:
        Complex (float real=0, float img=0) {
            this->real = real;
            this->img = img;
        };
        
        // you can either write like
        /* Complex add(Complex x) {
            Complex temp;
            temp.real = this->real + x.real;
            temp.img = this->img + x.img;

            return temp;
        }; */

        // or use
        Complex operator+(Complex x) {
            Complex temp;
            temp.real = this->real + x.real;
            temp.img = this->img + x.img;

            return temp;
        };

        // to use library function use reference &
        friend ostream &operator<<(ostream &os, const Complex &c) {
        os << c.real << " + " << c.img << "i";
        return os; // allows chaining like cout << c1 << c2;
    }
};

int main() {
    Complex C1(1,2);
    cout<<C1<<endl;

    Complex C2(2,2);
    cout<<C2<<endl;

    Complex C3 = C1 + C2;
    cout<<C3<<endl;

    cout<<C1+C2+C3; // nothing because friend functio is not used for chaining


    return 0;
};
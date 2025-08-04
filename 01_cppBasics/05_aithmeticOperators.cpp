#include <iostream>

int main()
{
    // Arithemtic: +, -, /, *, %

    // Relational: <, <=, >, >=, ==, !=

    // logical: &&, ||, !

    // Bitwise: &, |, ~, ^

    // increment and decrement: ++, --

    // Assignment: =

    // type casting
    int a = 5, b = 1;
    // dividing 2 int to get int
    float c;
    c = (int) a/b;
    std::cout << c; // 5

    // dividing 2 ints to get float
    c = (float) a/b; // 5.0 but prints as 5 only unlike python
    std::cout << c;

    c = (float) b/a; // no problem: 0.2
    std::cout << c;
    c = (int) b/a; // prints 0 ie floor of result 1/5 = 0.2 ==> floor(0.2) = 0
    std::cout << c;

    /* if we used int c to define c then no matter what we used it will return an int as answer but as we used float here using (int) b/a is returninf 0, an interger as answer */

    // when output is int
    int d;
    d = (int) a/b;
    std::cout << d; // 5

    // dividing 2 ints to get float when d is int
    d = (float) a/b; // 5
    std::cout << d;

    d = (float) b/a; // 0
    std::cout << d;
    d = (int) b/a; // 0
    std::cout << d;

    // mod operator % can't be performed on float datatypes, it is allowed only for char and int as we can store num in char datatype

    char e = 'e';
    char f = 'f';
    int s = f%e;
    int k = f;
    std::cout << s; // 1 as it divide ASCII code for it
    std::cout << k; // 102 ASCII code for character 'f' in ASCII code

    // below is also valid
    char g = 103;
    std::cout << g; // prints g as ASCII code for char 'g' is 103

}

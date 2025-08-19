/* Templates are used for generic programming ie genralize */

#include <iostream>

using namespace std;

template <class T>
T maximum(T x, T y)
{
    return x>y?x:y;
};

// to pass cusom class or datatype we need to define > in our class using operator overiding

// using 2 class and returning output as one of inputs' datatype
template <class T, class R>
T add(T x, R y)
{
    return x+y;
};

// Template Classes
// below is example of stack that only process integer input and output

/* class Stack
{
    private:
    int s[10];
    int top;

    public:
    void push(int x);
    int pop();
}; */

// to store float, string etc. other datatype we need to write different class or you can use templated to processing any datatype
template <class T>
class Stack
{
    private:
    T s[10];
    int top;

    public:
    void push(T x);
    T pop();
};

// write function outside
template <class T>
void Stack<T>::push(T x)
{
    // code here
};

template <class T>
T Stack<T>::pop()
{
    // code here
};

int main()
{
    // now use any datatype in function as long as they are same
    cout<<maximum(10,20)<<endl;
    cout<<maximum(10.1,1.2)<<endl;
    
    // cout<<maximum(10,20.1)<<endl; // error 

    cout<<add(1,1.5)<<endl; // here T is int so it return int 2
    cout<<add(1.5,1)<<endl; // here T is double so it return double 2.5

    // creating object of stack
    Stack<float> S1; // store float
    Stack<int> S2; // stores int

    return 0;
};
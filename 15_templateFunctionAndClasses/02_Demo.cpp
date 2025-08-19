/* #include <iostream>
using namespace std;

class Stack
{
private:
    int *stk;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        stk = new int[size];
    };

    void push(int x);
    int pop();
};

void Stack::push(int x)
{
    if (top==size-1)
    {
        cout<<"Stack is Full"<<endl;
    }
    else
    {
        top++;
        stk[top]=x;
    };
};

int Stack::pop()
{
    if (top == -1)
    {
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    else
    {
        return stk[top--];
    };
};

int main()
{
    Stack s(10);
    s.push(1);
    s.push(2);
    cout<<s.pop()<<endl;

    return 0;
}; */

// or use
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *stk;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        stk = new T[size];
    };

    void push(T x);
    T pop();
};

template <class T>
void Stack<T>::push(T x)
{
    if (top==size-1)
    {
        cout<<"Stack is Full"<<endl;
    }
    else
    {
        top++;
        stk[top]=x;
    };
};

template <class T>
T Stack<T>::pop()
{
    T x;
    if (top == -1)
    {
        cout<<"Stack is Empty"<<endl;
        return x;
    }
    else
    {
        return stk[top--];
    };
};

int main()
{
    Stack<int> s(10);
    s.push(1);
    s.push(2);
    cout<<s.pop()<<endl;

    Stack<char> s2(10);
    s2.push(99);
    s2.push(100);
    cout<<s2.pop()<<endl;

    Stack<double> s3(10);
    s3.push(9.9);
    s3.push(1.3);
    cout<<s3.pop()<<endl;

    return 0;
};

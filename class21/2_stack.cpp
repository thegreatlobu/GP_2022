#include<iostream>
using namespace std;

template<typename T>
class Stack
{
    public:
    explicit Stack(int n);
    ~Stack();
    Stack<T>& operator=(const Stack<T>&) = delete;
    Stack(const Stack<T>&) = delete;
    void push(T key);
    T pop();

    private:
    T *p_;
    int n_;//number of elements remains integer
    T *sp_;
};


//type T should support
//  default ctor
template<typename T>
Stack<T>::Stack(int n)
:p_(new T[n]), n_(n)
{
    sp_ = p_;
}


//type T should support
//  dtor
template<typename T>
Stack<T>::~Stack()
{
    delete[] p_;
}

//type T should support
//  assignment 
template<typename T>
void Stack<T>::push(T key)
{
    *sp_++ = key;
}


//type Q should support
//  copy ctor
template<typename Q>
Q Stack<Q>::pop()
{
    Q key = *--sp_;
    return key;
}   

class Number
{
    private:
    int val_;
    public:
    Number(int val = 0):val_(val){}
    friend ostream& operator<<(ostream& o, const Number& x);
};

ostream& operator<<(ostream& o, const Number& x)
{
    return o << x.val_;
}

//instantiation of class templates
//  a) explicit instantiation
//  b) default type paramaters
int main()
{
    #if 0
    Stack<int> s(10);
    s.push(111);
    s.push(222);
    // cout << s.pop() << "\t" << s.pop() << "\n";
    //operator(operator<<(cout, s.pop()), s.pop()) order of parameter evaluation is undefined
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
    #endif
    #if 0
    Stack<double> s(10);
    s.push(11.1);
    s.push(22.2);
    // cout << s.pop() << "\t" << s.pop() << "\n";
    //operator(operator<<(cout, s.pop()), s.pop()) order of parameter evaluation is undefined
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
    #endif
    Stack<Number> s(10);
    s.push(11.1);
    s.push(22.2);
    // cout << s.pop() << "\t" << s.pop() << "\n";
    //operator(operator<<(cout, s.pop()), s.pop()) order of parameter evaluation is undefined
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
    
}

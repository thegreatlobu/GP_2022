#include<iostream>
using namespace std;

#include "complex.h"

class MyNum
{
    private:
    int val_;
    
    public:
    MyNum(int val = 0) : val_(val) { } //internal linkage
    MyNum sqr() const { return val_ * val_;} //implicit conversion
    friend ostream& operator<<(ostream&, const MyNum&);
    friend MyNum square(const MyNum& n);
};

ostream& operator<<(ostream& o, const MyNum& n)
{
    return o << n.val_ << "\n";
}

MyNum square(const MyNum& n)
{
    return n.val_ * n.val_;
}

int main()
{
    Complex c1(2.2, 3.3);
    c1.disp();
    Complex c2(4.4);
    c2.disp();
    #if 0
    Complex c3(); //fn declaration
    //c3 is a fn declaration with no parameters returning an object of class Complex by value
    #endif
    Complex c3;
    c3.disp();

    Complex c4;
    c4 = c1.add(c2);
    c4.disp();

    Complex c5;
    //Complex Complex::add(const Complex& rhs) const
    c5 = c1.add(2.6);
    //5.user defined conversion
    //  -single aarguement ctor
    //  -type conversion op

    #if 0
    //Complex operator+(const Complex&) const
    //operator+(Complex *const this, const Complex& rhs)
    c3 = c1 + c2; //c1.operator+(c2)
    //operator fn : is a fn; syntactic sugar
    c3.disp();

    c3 = c1 + 2.5; //c1.operator(2.5) --> c1.operator(Complex(2.5))
    c3.disp();

    c3 = 2.5 + c1; //the arguement will be implicitly called using single parameter constructor but you cannot call functions with that object.
    #endif

    c3 = c1 + c2; //operator+(c1, c2)
    c3.disp();

    c3 = c1 + 2.5; //operator+(c1,Complex(2.5))
    c3.disp();   

    //cout << c1; //cannot be a member of complex class
    //first operand is not an object of complex class

    //make friend of complex class

    cout << c1 << c2;
    //c1 >> cout? not possible

    MyNum n(20);
    cout << n.sqr();
    cout << square(n); //convention demands
}

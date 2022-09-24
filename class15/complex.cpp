#include<iostream>
using namespace std;

#include "complex.h"

void Complex::disp() const
{
    cout << rp_ << "\t" << ip_ << "\n";
}

Complex::Complex(double rp, double ip)
:rp_(rp), ip_(ip)
{
    
}


//can we return by reference? NO temp is a local object 

//can we make this obj static(internal static) and return a reference to it?
//Complex c1,c2,c3,c4
//equal(c1.add(c2), c3.add(c4)) : always true

//can we make dynamic obj and return by reference?
//Complex *p; p = new Complex;...; return *p;
//Complex& Complex::add():
//  return *temp;
//Who cleans it?

//prefer to return by value
#if 0
Complex Complex::add(const Complex& rhs) const
{
    // Complex temp;
    // temp.rp_ = rp_ + rhs.rp_;
    // temp.ip_ = ip_ + rhs.ip_;
    //removed two extra assignments
    Complex temp(rp_ + rhs.rp_, ip_ + rhs.ip_);
    return temp;
}
#endif

#if 1
//return object optimization
Complex Complex::add(const Complex& rhs) const
{
    return Complex(rp_ + rhs.rp_, ip_ + rhs.ip_);
}
#endif

#if 0
Complex Complex::operator+(const Complex& rhs) const
{
    return Complex(rp_ + rhs.rp_, ip_ + rhs.ip_);
}
#endif

#if 0
Complex Complex::operator+(const Complex& lhs, const Complex& rhs) 
{
    return Complex(lhs.rp_ + rhs.rp_, lhs.ip_ + rhs.ip_);
}
#endif

Complex operator+(const Complex& lhs, const Complex& rhs) 
{
    return Complex(lhs.rp_ + rhs.rp_, lhs.ip_ + rhs.ip_);
}

ostream& operator<<(ostream& o, const Complex& c)
{
    return o << c.rp_ << " " <<  c.ip_ << "\n";
}
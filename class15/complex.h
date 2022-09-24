#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    private:
    double rp_;
    double ip_;

    public:
    //trivial ctor:
    //  class by default is in canonical form

    //making the ctor explicit is a rule
    //not making the ctor explicit is an exception
    //suppresses implicit conversion
    //explicit
    Complex(double = 0.0, double = 0.0);
    
    Complex add(const Complex&) const;
    // Complex operator+(const Complex&) const; //does not work
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend ostream& operator<<(ostream& o, const Complex& c);
    void disp() const;

};
#if 0
Complex operator+(const Complex& lhs, const Complex& rhs);
#endif
//add complex numbers
//  a) have two complex numbers as parameters and return the sum
//      -supports cascading 
//      -similar to the behaviour of built-in numeric types
//  b) have two complex numbers as paramaters + a reference to complex number
//      -latter gets the result
#endif
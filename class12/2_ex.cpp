#include<iostream>
using namespace std;

class A
{
    private:
    const int x_;
    const int y_;
    
    public:
    A(int x, int y);
    void disp() const;
};

//In const,
// member initialisation list
//required:
// 1) const member in class
// 2) reference member in class
// 3) base class sub-object
//can also be used to initialise varaible members
//order of initialisation of members in a class in member initialisation list:
//  3. order of declaration of members in the class: top to bottom, left to right
//     why? -> avoid dependency on fields in initialisation

A::A(int x, int y)
: x_(x), y_(y)
//: y_(100), x_(y_) // x gets some junk value

{
    cout << "ctor\n";
    // x_ = x; const cannot be assigned to
    // y_ = y;

}

void A::disp() const
{
    cout << x_ << "\t" << y_ << "\n";
}

int main()
{
    A a1(20, 30);
    a1.disp();
}
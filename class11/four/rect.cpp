#include<iostream>
using namespace std;
#include "rect.h"

void Rect::read()
{
    // cin >> this->length_ >> this->breadth_;
    //field: field which is part of the object through which the call is made
    cin >> length_ >> breadth_;
}

void Rect::disp() const
{
    cout << this->length_ << "\t" << this->breadth_ << "\n";
}

int Rect::find_area() const
{
    return length_ * breadth_;
}


//access control:
// based on class or based on object?
//  it is based on the type
//in a function of a class, we can access any member of any object of the same class
bool Rect::equal(const Rect& rhs) const
{
    return length_ == rhs.length_ && breadth_ == rhs.breadth_; 
}

void Rect::scale(int sf)
{
    length_ *= sf;
    breadth_ *= sf;
}

Rect Rect::transpose() const
{
    Rect temp;
    temp.length_ = breadth_;
    temp.breadth_ = length_;
    return temp;
}
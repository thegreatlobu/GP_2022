#include<iostream>
using namespace std;
#include "date.h"

ostream& operator<<(ostream& o, const date& d)
{
    return o << d.dd_ << "/" << d.mm_ << "/" << d.yy_ << "\n";
}

bool operator<(const date& l, const date& r)
{
    if(r.yy_ < l.yy_)
        return false;
    if(r.yy_ == l.yy_ && r.mm_ < l.mm_)
        return false;
    if (r.yy_ == l.yy_ && r.mm_ == l.mm_ && r.dd_ < l.yy_)
        return false;
    return true;
}

#if 0
//do not repeat the logic
date& date::operator++()
{
    //logic to increment the date
    ++dd_;
    return *this;
}

//two extra objects => 4 extra function calls(2 ctors and 2 dtors)  
//  1)temp 
//  2)return temp
date date::operator++(int)
{
    date temp(*this);
    //logic to increment the date
    ++dd_;
    return temp;
}
#endif

date& date::operator++()
{
    //logic to increment the date
    ++dd_;
    return *this;
}

date date::operator++(int)
{
    date temp(*this);
    //have the logic at one place 
    //make post call pre
    ++*this;    
    return temp;
}
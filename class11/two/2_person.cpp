#include<iostream>
using namespace std;
#include "2_person.h"

void person::read_one()
{
    cin >> this->name_ >> this->age_;
}

void person::display() const
{
    cout << this->name_ << this->age_;
}

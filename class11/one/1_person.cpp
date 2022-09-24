#include<iostream>
using namespace std;
#include "1_person.h"

void read_one(person& x)
{
    cin >> x.name_ >> x.age_;
}

void display(const person& x)
{
    cout << x.name_ << x.age_;
}
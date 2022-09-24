#include<iostream>
using namespace std;
#include "myvector.h"

myvector::myvector(int n)
:p_(new int[n]), n_(n)
{
    //some initialisation for testing
    for(int i = 0; i < n_; ++i)
    {
        p_[i] = i * i * i;
    }
}

myvector::~myvector()
{
    delete[] p_;
}
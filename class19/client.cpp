#include<iostream>
using namespace std;
#include "myvector.h"
#include<typeinfo>

void foo(const myvector& temp)
{

}

class Add
{
    public:
    int operator()(int x, int y){ return x + y;}
};


//ptr_t should support:
//  != ==
//  * : derefrencing : rvalue usage
//  ++ : pre and post
template <typename T, typename ptr_t, typename op_t>
T acc3(ptr_t first, ptr_t last, T init, op_t op)
{
    
    // cout << "ptr: " << typeid(ptr_t).name();
    #if 1
    while(*first != *last)
    {
        init = op(init, *first); //op.operator()(init, *first)
        ++first;
    }
    #endif
    return init;
}

int main()
{
    myvector v(5);
    foo(v);
    cout << acc3(v.begin(), v.end(), 0, Add());
}
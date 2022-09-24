#include<iostream>
using namespace std;


//callback based on object of functor class
//  a) compiler can deduce which fn is getting called therefore the code can be inlined

//  b) an object of a class can have state which could influence the behaviour
template <typename T, typename ptr_t, typename op_t>
T acc3(ptr_t first, ptr_t last, T init, op_t op)
{
    
    while(*first != *last)
    {
        init = op(init, *first); //op.operator()(init, *first)
        ++first;
    }
    return init;
}

int add(int x, int y){return x + y;}

class Add
{
    public:
    int operator()(int x, int y){ return x + y;}
};

int main()
{
    int a[] = {3, 1, 5, 2, 4};
    cout << "sum :" << acc3(a, a + 5, 0, add) << "\n";
    cout << "sum :" << acc3(a, a + 5, 0, Add()) << "\n";
}
#include <iostream>
using namespace std;
#include "mylist.h"


class Add
{
    public:
    int operator()(int x, int y){ return x + y;}
};


template <typename ptr_t>
void display(ptr_t first, ptr_t last)
{
	while(first != last) 
	{
		cout << *first << "\t";
        ++first; 
		
	}
    cout << "\n";
}

template <typename T, typename ptr_t, typename op_t>
T acc3(ptr_t first, ptr_t last, T init, op_t op)
{
    
    // cout << "ptr: " << typeid(ptr_t).name();
    #if 1
    while(first != last)
    {
        init = op(init, *first); //op.operator()(init, *first)
        ++first;
    }
    #endif
    return init;
}

int main()
{
    mylist l;
    l.insert(5);
    l.insert(6);
    l.insert(7);
    display(l.begin(), l.end());
    cout << acc3(l.begin(), l.end(), 0, Add());
}
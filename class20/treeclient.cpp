#include<iostream>
using namespace std;
#include "mytree.h"
#include<typeinfo>

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
        cout << init << "\n";
        ++first;
    }
    #endif
    return init;
}

int main()
{
    mytree t;
    t.insert(4);
    t.insert(2);
    t.insert(1);
    t.insert(5);
    t.insert(3);
    t.insert(6);
    t.insert(4);
    t.inorder();
    cout << "\n";
    cout << acc3(t.begin(), t.end(), 0, Add());
}
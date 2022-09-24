#include<iostream>
using namespace std;
#include "date.h"

// ptr_t should support
//component type (*p) where p is of type ptr_t
//  put to operator (<<)
//  

template <typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
    while(first != last)
    {
        cout << *first << "\n";
        ++first;
    }
    cout << "\n";
}

template<typename T>
void myswap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
/*
    T temp; //T should have default ctor
    temp = x;
*/

//T should support
//  operator<
template<typename T>
void mysort(T a[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[i])
            {
                myswap(a[i], a[j]);
            }
        }
    }
}


int main()
{
    date d1(15, 8, 1947);
    cout << d1;
    date d[] = {
        {26, 12, 2004},
        {26, 1, 2001},
        {30, 1, 1948},
        {11, 1, 1966},
        {11, 9, 2001} 
    };
    // disp(d, d + 5);
    // mysort(d, 5);
    // disp(d, d + 5);
    date d2 = d1;
    //d1 and d2 have the same date
    date d3;  
    d3 = ++d1; //d1.operator++() compiler passes no argument for pre increment
    cout << d1 << d3;
    d3 = d2++; //d2.operator++(1) compiler passes integer argument for post increment
    cout << d2 << d3;
}
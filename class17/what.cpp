#include<iostream>
using namespace std;

#if 0
void disp(int *first, int *last)
{
    while(first != last)
    {
        cout << *first << "\t";
        ++first;
    }
    cout << "\n";
}
#endif

template <typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
    while(first != last)
    {
        cout << *first << "\t";
        ++first;
    }
    cout << "\n";
}

#if 0
void myswap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}


void mysort(int a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n - 1; ++j)
        {
            if (a[j] < a[i])
            {
                myswap(a[i], a[j]);
            }
        }
    }
}
#endif

//T should support
//  copy ctor
//  assignment
//  

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
    int a[] = {33, 11, 22, 44, 55};
    disp(a, a + 5);
    mysort(a, 5);
    disp(a, a + 5);
    double b[] = {3.3, 1.1, 2.2, 4.4, 5.5};
    disp(b, b + 5); // ptr cannot be converted
    mysort(b, 5);
    disp(b, b + 5);
}
#include<iostream>
using namespace std;

int main()
{
    int a[] = {11,22,33,44,55};
    int *p(a+5); //p is dangling pointer(access; no location)
    cout << a << "\t" << p << "\t" << *(p -1) << "\n";
    cout << (p - a) << "\n"; //5, bet p and a there are 5 components of type *p

    //dangling pointers are not dangerous
    //derefrencing dangling pointers is an undefined behavior
    
}
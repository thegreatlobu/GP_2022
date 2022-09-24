/*
pointer:
    may be initialized
    should be explicitly derefrenced
    pointer can be changed
    pointer can be grounded/null

reference:
    has to be initialized
    derefrences implicitly
    can never be changed
    can never be null
*/

#include<iostream>
using namespace std;

int main()
{
#if 0    
    int a(10);
    int b(20);
    int *p(&a);
    int *q;
    cout << *p << "\n";
    *p = 30;
    p = &b;
    p = nullptr;
    cout << *p << "\n";
#endif
    int a(10);
    int b(20);
    int *p;
    //r always refers to a 
    //sort of alias for a
    int& r(a); //reference to int
    cout << r << "\n"; //cout << a << "\n"
    a = 30;
    cout << r << "\n";
    r = 11;
    cout << a << "\n";
    r = b; // a = b
}
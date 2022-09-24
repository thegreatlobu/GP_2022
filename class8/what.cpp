#include<iostream>
using namespace std;


//compile time : array is an array
//runtime : array degenerates to pointer

int foo(int *ptr)
{
    return reinterpret_cast<int>(ptr);
}

int main()
{
    int a[] = {11, 33, 55, 44, 22}; //C array
    a[5] = 111; //undefined behaviour, index out of bounds is not checked
    cout << a[5] << "\n";

    int *p = a;
    cout << boolalpha;
    cout << (p==a) << *p << "\n";
    cout << (*p==*a) << "\n";
    cout << (foo(p) == foo(a)) << "\n";
    cout << (sizeof(p) == sizeof(a)) << "\n"; //false

    int x = 10;
    int b;
    b = sizeof(x = 20); //x is undefined
    //sizeof (<expr>) or sizeof(<type>)
    //in an implementation, there will be a table of type and size
    //to find size only type is required
    //y = sizeof(x = 20)
    //y = sizeof(int)
    //table lookup at compile time
    //a const value
    cout << x << "\n";//10
}
#include<iostream>
using namespace std;

int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

int caller(int (*fn)(int, int), int x, int y)
{
    return fn(x, y); //callback
}


//callback returns a boolean value: predicate
int main()
{
    int (*ptr_fn)(int, int); //ptr_fn: variable 
    //pointer to a fn taking two int by value and return by value
    ptr_fn = add;
    cout << (*ptr_fn)(20, 30) << "\n";

    ptr_fn = &add;
    cout << (*ptr_fn)(20, 30) << "\n";

    cout << ptr_fn(20, 30) << "\n";

    cout << caller(add, 20, 30) << "\n";
    cout << caller(mul, 20, 30) << "\n";
}
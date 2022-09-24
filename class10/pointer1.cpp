#include<iostream>
using namespace std;

int main()
{
    int a[5];
    cout << "a:" << a << "\n";
    cout << "&a:" << &a << "\n"; //same value

    cout << "a + 1:" << (a + 1) << "\n";
    cout << "&a + 1:" << (&a + 1) << "\n";

    //cout << &(a + 1) << "\n"; //a + 1 is a temporary => error
    //++a; // no modifiable lvalue

}

//a: pointer to an int
//&a: pointer to an array of 5 int

/*

void foo(int a[][]); //NO
void foo(int **a); //NO
void foo(int a[5][]); //NO
void foo(int a[][4]); //YES
void foo(int (*a)[4]); //YES

void bar(int size, int a[][size]);

int a[5][4];
foo(a);

*/
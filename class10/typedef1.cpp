#include<iostream>
using namespace std;

int a; //variable
typedef int t; //type
t b;
typedef int* t1; //t1: type: pointer to int
t1 x, y; //x,y are pointers

#define t2 int*
t2 c,d; //int* c,d , d is an int

int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

int main()
{
    int (*ptr_fn)(int, int); //variable
    typedef int (*ptr_fn_t)(int, int); //type
    ptr_fn_t fn;
    fn = add;
    cout << fn(20,30) << "\n";
}
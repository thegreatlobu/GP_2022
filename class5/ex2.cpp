#include<iostream>
using namespace std;

int main()
{
    #if 0
    //C:
    int *p;
    p = (int*)malloc(sizeof(int));
    //...
    free(p);
    //can free change the value of p? NO
    //parameter passing is by value in C
    //p will be dangling
    int *q;
    q = (int*)malloc(sizeof(int) * 4);
    //...
    free(q);
    //free(q+1)?????? undefined
    #endif

    //C++
    //new operator:
    //  operator new to allocate memory
    //  initialize (calls ctor)
    
    //delete operator:
    //  de_initialization (calls dtor)
    //  operator delete to de_allocate memory

    int *p;
    p = new int(10); //may not have bookkeeping
    cout << *p << "\n";
    delete p;

    int *q;
    q = new int[4]; //new[] op // will have bookkeeping
    //array on the heap
    cout << *q << "\n";
    delete []q; //delete [] op

}
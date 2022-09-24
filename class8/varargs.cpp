#include<iostream>
using namespace std;
#include<cstdarg> //stdarg.h in C
#include "varargs.h"

int sum(int x, ...)
{
    va_list va;
    //make va point to the first unnamed parameter
    va_start(va, x);
    //2nd argument: last named parameter

    int s = 0;
    while (x--)//execute x times
    {
        s += va_arg(va, int); //2nd argument: expected type
        //gets the value from the stack of the specified type and advances va to the next location
    }
    va_end(va);
    //breaks the association of va with the stack
    return s;
}

//va_list : is a typedef
//used to create interface
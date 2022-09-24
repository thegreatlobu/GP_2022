#include<iostream>
using namespace std;
#include<cstdarg> //stdarg.h in C
#include "varargs.h"

int main()
{
    cout << sum(3, 10, 30, 50) << "\n";
    cout << sum(2, 20, 50) << "\n";
}
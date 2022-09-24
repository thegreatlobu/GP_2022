#include<iostream>
using namespace std;

/*
declaration : only for global variables extern int a
                for the compiler

definition : causes memory allocation
             when and where it happens depends on storage class
             one definition rule

initialization : 
                at the point of definition
                only once
                not an expression
                more efficient than assignment
                define a variable only when we know how to initialize
                default init:
                    global, static variables : initialized to 0
                    others are not initialized 
assignment : 
                an expr, low precedence, right to left

pointers : 
            alias
            dangling pointer: no location; no access
            garbage => memory leak; location no access  

*/

int main()
{
    int a = 10;
    int b(20);
    int c{20};
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    int d(2.5); //converts double to int; narrowing
    cout << d << "\n";
    //int e{2.5} //NO

}
#include<iostream>
using namespace std;
#include "ex4a.h"

int main()
{
    int a(10);
    int b(20);
    cout << sum(a, b) << "\n";
    cout << sum(3.6, 4.7) << "\n"; //sum((int)3.6,(int(4.7))) =>compiler job
    double c(2.6);
    double d(4.5);
    cout << sum(c, d) << "\n";
    
}

//prototype
//  -matching in arguements to parameters
//  #,type and order
//  # should match
//  corresponding types may not match
//  -overloading
//  -default parameters

//Matching arguements to parameters:
//1.exact match or trivial conversions
//      array => pointer
//      variable => const
//      derived class obj => base class obj
//2.generic functions
//3.promotion
//4.standard conversion
//5.user defined conversion
//  single arguement ctor
//  type conversion operator 
//6.type unsafe conversion
//  pointer => void*
//  variable # arguements

//promotion:
//int is the preferred integral type
//double is the preferred floating point type
//conversion of integral types to int
//  float to double
//is promotion
//no loss of precision

//std conversion:
//conversion of any numeric type to any other numeric type
//can have loss of precision

//struct padding:
//struct A
//{
//  char ch; //1 byte
//  int n; //size of word - 4 bytes
//}

//struct A a; //5 or 8 bytes -> undefined
//may use compiler directives to change the alignment
//make a struct for space or time efficiency
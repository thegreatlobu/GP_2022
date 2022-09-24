#include<iostream>

int main()
{
    std::cout << "Hello World\n";
    return 0;
}

//first pgrm in C++

//program structure:
//  as in C
//  entry fn is main
//  case sensitive
//  free format source code

//  output: 
//  << insertion operator "put to operator"
//  cout: variable associated with the console : output stream
//        object of output stream
//  left of <<: ostream object

//to avoid clash of global names: namespace
//namespace names should be distinct
//qualify each name by its namespace name

//std: one of the namespaces
//namespace is not a type or class or variable or a control structure
//          is a wrapper that allows you to use global names

// header file naming and usage:
// before C++11: iostream.h
// after C++11: iostream: introduces the namespace std
#include<iostream>
using namespace std;

extern int a; //something for the linker; declaration 
//for the compiler; nothing at runtime
extern const int b;

int main()
{
    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n"; 
}

// one definition rule : any entity can be defined only once

//linker error:
//a)multiple definitions
//b)

//constant folding:
//use of the constant is replaced by its value
//const may not have a location at all

//C++: const has internal linkage by default 

//make a const available across translations, extern the definition 

/*
linkage:
external linkage:
//  name can be used across translations
//  global
internal linkage:
//  name can be used only in that translation
//  external static(linkage)
no linkage
//  name cannot be used outside the block
//  automatic
//  internal static(life)
*/

//video:
//Scott Meyers:  Most Important Design Guideline
//Bjarne Stroustrup: why we should not use linked lists

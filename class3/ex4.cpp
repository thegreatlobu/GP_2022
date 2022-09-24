/*
lvalue : left of assignment operator
rvalue : right of assignment operator

right: any expression
left: variable
can we have an expression on the left
int *p;
int a = 10;
p = &a;
*p = 20;
derefrencing a pointer is both l and r value

x = 10;
y = x++ //post
//copy of x is made to a variable  with no name; temporary variable 
//x is incremented, temp is copied to y, temp is removed

x = 10; 
y =++x; //pre
//do we need a temporary? NO

is x++ a lvalue?
is ++x a lvalue?
C: both are no
C++: ++x is a lvalue

x++ ++ no
++ ++x yes

if the result of an operation is stored in a variable of the programmer it is a lvalue
if it is temporary it is rvalue
*/
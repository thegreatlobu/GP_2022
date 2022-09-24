#include<iostream>
using namespace std;

class A
{
    public:
    A(int, int){cout << "ctor\n";}
    void operator()(int, int){cout << "fn call operator\n";}

};

int main()
{
    A a(1, 2); //ctor call
    a(3, 4); //a.operator()(3,4)
    A(5, 6)(7, 8);
}
// An object of the class supporting the function call operator becomes callable 
//  -such an object is called functor
//  -such a class is called a functor class 
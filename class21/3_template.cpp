#include<iostream>
using namespace std;
#include<typeinfo>

//default type parameter
//all parameters can be default
//left parameters to be specified in instantiation
//right parameters are taken as default

template<typename T = int>
class A
{

};
template<typename T1 = int, typename T2 = double>
class B
{

};

template<typename T1 = int, typename T2 = T1>
class C
{

};

template<typename T1 = int, typename T2 = A<T1>>
class D
{

};

int main()
{
    A<int> a1;
    cout << typeid(a1).name() << "\n";
    A a2; //A<> a2;
    cout << typeid(a2).name() << "\n";
    A<A<char>> a3;
    cout << typeid(a3).name() << "\n";

    B<char, int> b1;
    cout << typeid(b1).name() << "\n";
    B<char> b2;
    cout << typeid(b2).name() << "\n";
    B<> b3;
    cout << typeid(b3).name() << "\n";

    C<char, int> c1;
    cout << typeid(c1).name() << "\n";
    C<char> c2;
    cout << typeid(c2).name() << "\n";
    C<> c3;
    cout << typeid(c3).name() << "\n";

    D<char, int> d1;
    cout << typeid(d1).name() << "\n";
    D<char> d2;
    cout << typeid(d2).name() << "\n";
    D<> d3;
    cout << typeid(d3).name() << "\n";
}


#include<iostream>
using namespace std;

template<typename T1, typename T2>
class A
{
    public:
    void foo() const{cout<<"one"<<"\n";}
};


template<typename T1, typename T2>
class A<T1*, T2*>
{
    public:
    void foo() const{cout<<"four"<<"\n";}
};

//complete specialization 
template<>
class A<int, char>
{
    public:
    void foo() const{cout<<"two"<<"\n";}
};

template<>
class A<int, int>
{
    public:
    void foo() const{cout<<"three"<<"\n";}
};

template<>
class A<char*, long*>
{
    public:
    void foo() const{cout<<"five"<<"\n";}
};

template<>
class A<int*, int*>
{
    public:
    void foo() const{cout<<"six"<<"\n";}
};

int main()
{
    A<int, char> a1;
    a1.foo();
    A<double, long> a2;
    a2.foo();
    A<int, int> a3;
    a3.foo();
    A<int*, double*> a4;
    a4.foo();
    A<char*, long*> a5;
    a5.foo();
    A<int*, int*> a6;
    a6.foo();
}
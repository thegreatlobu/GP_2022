#include<iostream>
using namespace std;

class Ex
{
    public:
    void foo(double);
    private:
    void foo(int);
};

void Ex::foo(double)
{
    cout << "double\n";
}

void Ex::foo(int)
{
    cout << "int\n";
}

int main()
{
    Ex ex;
    ex.foo(25);//compile time error
}
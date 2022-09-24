#include<iostream>
using namespace std;
//from the callers perspective, there is no difference bt the two fns
void bar(int x)
{
    cout << "bar x\n";
}

void bar(const int x)
{
    cout << "const bar x\n";
}

void foo(int& x)//callers arguement can change
{
    cout << "foo x\n";
}

void foo(const int& x)//callers arguement cannot change
{
    cout << "const foo x\n";
}

int main()
{
    foo(10);
    int a = 20;
    foo(a);
}
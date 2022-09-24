#include<iostream>
using namespace std;

void foo(int a)
{
    cout << a << "\n";
}

void foo(char a)
{
    cout << a << "\n";
}

// void foo(double a)
// {
//     cout << a << "\n";
// }

int main()
{
    foo(14);
}
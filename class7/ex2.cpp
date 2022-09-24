#include<iostream>
using namespace std;

int f1(int x)
{
    return x;
}

int& f2(int& x)
{
    return x;
}

//bad fn returns a reference to local variable
//if we return a reference, it should refer to something which exists in the calling environment
int& f3(int x)
{
    return x;
}

int main()
{
    int a = 10;
    int b;
    b = f1(a);
    b = f2(a);
    f2(a) = 20;
    cout << a << "\n";
    b = f3(a);
    cout << a << "\n"; 
}
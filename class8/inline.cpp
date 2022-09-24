#include<iostream>
using namespace std;

//inline fn:
//  -request to compiler
//  -compile time mechanism
//  an inline fn has the same semantics as an out of line fn
//  might introduce local variables to mimic parameters


inline int sq(int x);
int sq(int x)
{
    return x * x;
}

int main()
{
    int n;
    cin >> n;
    cout << sq(n) <<"\n";
}
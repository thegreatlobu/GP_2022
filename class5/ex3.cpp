#include<iostream>
using namespace std;

void what(int& x, int& y) // => gcd
{
    int a(x); int b(y);
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    x /= a; y/= b;
}

int main()
{
    int m(25); int n(15);
    what(m, n);
    cout << m << "\t" << n << "\n"; 
    what(m,m);
    cout << m << "\n";
}
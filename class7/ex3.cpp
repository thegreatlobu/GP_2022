#include<iostream>
using namespace std;

int main()
{
    const int a = 20;
    const int& r = 20;

    int b = 20;
    int& rb1 = b;
    rb1 = 30;
    cout << b << "\n";

    //conversion of variable to const: is trivial
    //conversion of const to variable requires an explicit casting
    const int& rb2 = b;
    cout << rb2 << "\n";
    b = 10;
    cout << rb2 << "\n";
}
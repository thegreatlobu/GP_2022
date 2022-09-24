#include<iostream>
using namespace std;

#define sq(x) x*x
#define sq1(x) (x)*(x)

//advantages of macro 
//  -can be generic
//      -works on different types
//      C++ : prefer templates
//  -no overhead of a function call
//      -cache invalidation
//      C++ : prefers inline
//-------------------------------------------------
//template instantiations : per type and not per call
//disadvantages:
//  -per call -> leads to code bloat
//  violates the law of least expectation

int main()
{
    cout << sq(10) << "\n";
    cout << sq(2.5) << "\n";
    cout << sq(5) << "\n";

    cout << sq1(5+5) << "\n"; //5 + 5*5 + 5 = 35 but expected 100
    cout << 1000 / sq1(5+5) << "\n"; // 1000 / (5+5) * (5+5) 
}
#include<iostream>
using namespace std;
#include<cstring>

//but for types, these are similar
//can the compiler generate the code for different types 
//given a skeletal code?
#if 1
int sq(int x)
{
    return x * x;
}

double sq(double x)
{
    return x * x;
}
#endif

#if 0
template <typename T> 
T sq(T x)
{
    return x * x;
}
#endif

//instantiation :
//  create the fn based on the call
//  a) implicit instantiation:
//          compiler deduces the type of parameter based on matching of arguements to parameters
//compile time mechanism
//results in overloaded fns
//  -algo different : overloading
//  -algo same : templates
//  -algo diff;same abstraction : 
//  b) explicit instantiation:
//

//compiler creates:

// int sq(int x)
// {
//     return x * x;
// }

// double sq(double x)
// {
//     return x * x;
// }


#if 1
template <typename T> 
bool eq(T a, T b)
{
    return a == b;
}
#endif

template <> //specialization
bool eq(char* a, char* b)
{
    return strcmp(a, b) == 0;
}

int main()
{
    cout << sq(10) << "\n";
    cout << sq(2.5) << "\n";
    cout << sq(5) << "\n"; //no new instantiation
    cout << sq(2.5f) << "\n"; //new fn instantiated

    cout << boolalpha << "\n";
    cout << eq(65, 65) << "\n";
    //specifying a list of types to match the of typenames in the template definition
    cout << eq<char>('A', 65) << "\n";

    char a[] = "pes";
    char b[] = "pes"; // reference semantics
    cout << eq(a , b) << "\n";
}

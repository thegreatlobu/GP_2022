#include<iostream>
using namespace std;

#if 0
int acc1(int *first, int* last)
{
    int init = 0;
    while(*first != *last)
    {
        init += *first;
        ++first;
    }
    return init;
}
#endif


template <typename T, typename ptr_t>
T acc1(ptr_t first, ptr_t last)
{
    T init = T(); //call to default ctor; int() => 0, double() => 0.0
    while(*first != *last)
    {
        init += *first;
        ++first;
    }
    return init;
}


template <typename T, typename ptr_t>
T acc2(ptr_t first, ptr_t last, T init)
{
    
    while(*first != *last)
    {
        init += *first;
        ++first;
    }
    return init;
}

//callback based on pointer to function
//  a) we cannot make out which function is being called back at compile time
//      function call cannot be inlined
//  b) callback is based on a pointer; does not have any attributes
//      no state
//   
template <typename T, typename ptr_t, typename op_t>
T acc3(ptr_t first, ptr_t last, T init, op_t op)
{
    
    while(*first != *last)
    {
        init = op(init, *first);
        ++first;
    }
    return init;
}

int add(int x, int y){return x + y;}
int mul(int x, int y){return x * y;}
int max(int x, int y){return (x > y) ? x : y;}
int main()
{
    #if 0
    int a[] = {3, 1, 5, 2, 4};
    cout << "sum :" << acc1(a, a + 5) << "\n";
    double b[] = {3.3, 1.1, 5.5, 2.2, 4.4};
    cout << "sum :" << acc1(b, b + 5) << "\n";
    #endif

    #if 0
    //only way of instantiation is explicit
    int a[] = {3, 1, 5, 2, 4};
    cout << "sum :" << acc1<int, int*>(a, a + 5) << "\n";
    double b[] = {3.3, 1.1, 5.5, 2.2, 4.4};
    cout << "sum :" << acc1<double, double*>(b, b + 5) << "\n";

    //combination of implicit and explicit instantiation
    cout << "sum :" << acc1<int>(a, a + 5) << "\n"; //also works
    #endif

    #if 0
    int a[] = {3, 1, 5, 2, 4};
    cout << "sum :" << acc2(a, a + 5, 0) << "\n";
    double b[] = {3.3, 1.1, 5.5, 2.2, 4.4};
    cout << "sum :" << acc2(b, b + 5, 0.0) << "\n";
    #endif

    int a[] = {3, 1, 5, 2, 4};
    cout << "sum :" << acc3(a, a + 5, 0, add) << "\n";
    cout << "mul :" << acc3(a, a + 5, 1, mul) << "\n";
    cout << "max :" << acc3(a + 1, a + 5, a[0], max) << "\n";

}
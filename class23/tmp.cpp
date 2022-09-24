#include<iostream>


template<typename T, T Value>
struct integral_constant{
    static constexpr T value = Value;
};

struct true_type
: integral_constant<bool, true> {};

struct false_type
: integral_constant<bool, false> {};

template<typename T, typename V>
struct is_same : false_type {};

template<typename T>
struct is_same<T, T> : true_type {};

template<bool Value, typename T, typename V>
struct conditional
{
    using type = V;
};

template<typename T, typename V>
struct conditional<true, T, V>
{
    using type = T;
};

template<bool Value, typename T>
struct enable_if;

template<typename T>
struct enable_if<true, T>
{
    using type = T;
};


//Approach 1:
//If you have i,N. i is the square root of N, iff i * i = N
//N [1,....N] start with 1,2,3,4...i*i == N

//Approach 2:
//binary search: midpoint * midpoint == N
//if mid*mid < N [1, mid]
//if mid*mid > N [mid + 1, N]
// 120 sqrt(120) = 11

template<uint32_t I, uint32_t Value>
struct SqrtImpl
{
    static constexpr uint32_t value = ((I * I) == Value) ? I : SqrtImpl<I + 1, Value>::value;
};

template<uint32_t I>
struct SqrtImpl<I, I>
{
    static constexpr uint32_t value = I;
};


template<uint32_t Value>
struct Sqrt : SqrtImpl<1, Value> {};    



template<uint32_t Value, uint32_t start, uint32_t last>
struct sqrt_impl
{
    static constexpr uint32_t mid = (start + last) / 2;
    static constexpr uint32_t value = conditional<(mid * mid) <= Value, sqrt_impl<Value, mid, last>, sqrt_impl<Value, start, mid - 1>>::type::value;
};

template<uint32_t Value, uint32_t T>
struct sqrt_impl<Value, T, T>
{
    static constexpr uint32_t value = T;
};

template<uint32_t Value>
struct sqrt : sqrt_impl<Value, 1, Value>{};



int issqrt(int Value, int start, int last)
{
    int mid = (start + last) / 2;
    
    if (start == last)
        return mid;

    if (mid * mid <= Value)
        return issqrt(Value, mid, last);
    else
        return issqrt(Value, start, mid - 1);
}


int main()
{
    std::cout << integral_constant<int, 5>::value << "\n";
    std::cout << is_same<float, int>::value << "\n";
    // std:cout << is_same<uint, uint32_t>::value << "\n"; //substitution error is not a failure

    std::cout << is_same<typename conditional<sizeof(int) == 4, float, double>::type, float>::value << "\n";  
    std::cout << is_same<typename conditional<sizeof(int) == sizeof(long), float, double>::type, double>::value << "\n";
    std::cout << is_same<typename enable_if<sizeof(int) == 4, float>::type, float>::value << "\n";
    // std::cout << is_same<enable_if<sizeof(int) == sizeof(char), bool>::type, bool>::value << "\n";
    std::cout << Sqrt<121>::value << "\n";
    // std::cout << sqrt<121>::value << "\n";
}
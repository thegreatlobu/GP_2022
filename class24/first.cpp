#include<iostream>


template<typename T>
struct ReturnType;

template<>
struct ReturnType<float*>
{
    using RT = double;
    static constexpr RT val = 300.0f;
};

template<>
struct ReturnType<int*>
{
    using RT = long;
    static constexpr RT val = 100L;
};

template<>
struct ReturnType<char*>
{
    using RT = int;
    static constexpr RT val = 128;
};
#if 0
template<typename T>
typename ReturnType<T>::RT Accumalate(T first, T last) //-> decltype(std::declval<T>()) //-> to specify return type, declval returns rvalue reference of T
{
    #if 0
    decltype(*first) accumalator{};
    //compiler sets type to *first
    #endif
    typename ReturnType<T>::RT accumalator = ReturnType<T>::val;
    while(first != last)
    {
       accumalator += *first;
       ++first;
    }
    return accumalator;
}
#endif
#if 0
template<typename T, typename RetTy = ReturnType<T>, typename _RT = typename RetTy::RT>
_RT Accumalate(T first, T last) //-> decltype(std::declval<T>()) //-> to specify return type, declval returns rvalue reference of T
{
    #if 0
    decltype(*first) accumalator{};
    //compiler sets type to *first
    #endif
    _RT accumalator = RetTy::val;
    while(first != last)
    {
       accumalator += *first;
       ++first;
    }
    return accumalator;
}
#endif
#if 0
template<typename T, typename _RT = typename ReturnType<T>::RT>
_RT Accumalate(T first, T last) //-> decltype(std::declval<T>()) //-> to specify return type, declval returns rvalue reference of T
{
    #if 0
    decltype(*first) accumalator{};
    //compiler sets type to *first
    #endif
    _RT accumalator{};
    while(first != last)
    {
       accumalator += *first;
       ++first;
    }
    return accumalator;
}
#endif
template<typename T, typename _RT = typename ReturnType<T>::RT, typename AccumalationPolicy>
_RT Accumalate(T first, T last) //-> decltype(std::declval<T>()) //-> to specify return type, declval returns rvalue reference of T
{
    #if 0
    decltype(*first) accumalator{};
    //compiler sets type to *first
    #endif
    _RT accumalator = AccumalationPolicy::init;
    while(first != last)
    {
       accumalator += AccumalationPolicy::op(*first, accumalator);
       ++first;
    }
    return accumalator;
}




int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    char array_char[] = {'a', 'b', 'c', 'd', 'e'};
    float array_float[] = {100.6f, 345.5f, 89, 231.4f};
    // std::cout << Accumalate(array, array + sizeof(array)/sizeof(int)) << "\n";
    // std::cout << Accumalate(array_char, array_char + 5) << "\n";
    // std::cout << Accumalate(array_float, array_float + 4) << "\n";
    std::cout << Accumalate(array_float, array_float + sizeof(array_float)/sizeof(float), [](long x, long y) -> long { return x * y; }) << "\n";
}
#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class multiply
{
    public:
    T operator()(T first, T second){return first * second;}
};

template<typename T, typename iterator, typename operation>
T accumulate(iterator iter, iterator last, T init, operation op )
{
    T acc = init;
    while(iter != last)
    {
        acc = op(acc, *iter);
        ++iter;
    }
    return acc;
}

template<typename T>
auto Begin(T &container)
{
    return container.begin();
}

// template<typename T, int N>
// auto Begin(T[N] &container)
// {
//     return &container[0];
// }


int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //uniform initialisation
    cout << accumulate(array, array + 10, 1, multiply<int>()) << "\n";
    cout << accumulate(v1.begin(), v1.end(), 1, multiply<int>());
}
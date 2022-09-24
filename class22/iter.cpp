#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
using namespace std;


//Reqirements of Input Iterator:
//== !=
//deref: rvalue
//post and pre increment
template<typename T> 
void display(T iterator, T end)
{
    while(iterator != end)
    {
        cout << *iterator << "\n";
        ++iterator;
    }
}

//T is input iterator
//Requirements of U -> Output Iterator:
// deref: lvalue
// post/pre increment

template<typename T, typename U>
void Copy(T first, T last, U dstfirst)
{
    while(first != last)
    {
        *dstfirst = *first;
        ++first;
        ++dstfirst;
    }
}


template<typename T>
class square
{
    public:
    T operator()(T x){return x*x;}
};


//Requirements of forward iterator -> input + output iterator
// == !=
// deref: lvalue and rvalue
// post/pre increment
template<typename T, typename Transform>
void Replace(T iter, T end, Transform Trans)
{
    while(iter != end)
    {
        *iter = Trans(*iter);
        ++iter;
    }
}

template<typename T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

//Requirements of bidirectional iterator
// != ==
// deref: rvalue and lvalue
// post/pre increment and decrement
template<typename T>
void Reverse(T first, T last)
{
    while((first != last) && (first != (--last)))
    {
        Swap(*first, *last);
        ++first;
    }
}

//Requirements of random access iterator
// != ==
// deref: rvalue and lvalue
// post/pre increment and decrement
// + - 
// += -=



int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //uniform initialisation
    list<int> l1{100, 200, 300, 400, 500}; //doubly linked list
    forward_list<int> fwl1{800, 900, 1000}; //singly linked list
//     display(begin(array), end(array));
//     display(begin(v1), end(v1));
//     display(begin(l1), end(l1));
//     display(begin(fwl1), end(fwl1));
    int first[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int second[10];
    Copy(begin(first), end(first), begin(second));
    // display(begin(second), end(second));
    Replace(begin(second), end(second), square<int>());
    // display(begin(second), end(second));
    Reverse(begin(second), end(second));
    // display(begin(second), end(second));

    auto it = begin(v1);
    auto last = end(v1);
        // it += 4;
        // cout << *it;
    // cout << (end - it);
}
#include<iostream>
using namespace std;

//returns 1 if found else returns -1
// int array_search(int *arr, int size, int target)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == target)
//             return 1;
//     }
//     return -1;
// }

#if 0
int* better_search(int* first, int* last, int key)
{
    //while(first < last) NO dangling pointer
    //while(first < last) ok
    while(first != last) //preferred
    {
        if(*first == key)
        {
            return first;
        }
        ++first;
    }
    return first;
}
#endif

#if 0
int* better_search(int* first, int* last, int key)
{
    //while(first < last) NO dangling pointer
    //while(first < last) ok
    while(first != last && *first != key) //preferred
    {
        ++first;
    }
    return first;
}
#endif

//T should support:
//
template <typename T>
T* search(T* first, T* last, T key)
{
    while (first != last && *first != key)
    {
        ++first;
    }
    return first;
}

int main()
{
    int arr2[] = {5, 6, 7, 8, 9};
    int arr[] = {1, 2, 3, 4, 5};
    char st[] = {'K','a','l','a','s','h'};
    int* res;
    res = search(arr, arr + 5, 4);

    if  (res == arr + 5)
    {
        cout << "not found" << "\n";
    }
    else
    {
        cout << "found " << *res << "\n";
    }

    res = search(arr2, arr2 + 5, 11);

    if  (res == arr2 + 5)
    {
        cout << "not found" << "\n";
    }
    else
    {
        cout << "found " << *res << "\n";
    }
    
    char *result;
    result = search(st, st + 6, 'l');
    if  (result == st + 5)
    {
        cout << "not found" << "\n";
    }
    else
    {
        cout << "found " << *result << "\n";
    }
}
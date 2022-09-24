#include<iostream>
#include<vector>


template <typename iterator>
void FindQuartileRanges(iterator first, iterator last)
{
    int size = 0;
    iterator temp = first;
    while (temp != last)
    {
        ++size;
        ++temp;
    }
    // std::cout << size << "\n";
    int mid_point = (size / 2);
    int end_of_q1 = (mid_point / 2);
    int end_of_q3 = mid_point + ((size - mid_point) / 2);
    std::cout << "First Quartile Range:" << "\n";
    int i;
    for(i = 0; i < end_of_q1 ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << "\nSecond Quartile Range:" << "\n";
    // range += size / 4;
     for(; i < mid_point ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << "\nThird Quartile Range:" << "\n";
    // range += size / 4;
     for(; i < end_of_q3 ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << "\nFourth Quartile Range:" << "\n";
    // range += size / 4 + 1;
     for(; i < size ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
}

int main()
{
    std::vector<int> v1;
    for (int i = 16; i < 57; ++i)
    {
        v1.push_back(i);
    }

    FindQuartileRanges(v1.begin(), v1.end());
}
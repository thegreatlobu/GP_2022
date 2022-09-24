#include<iostream>
#include<vector>
#include<list>

template<typename iterator>
class IterRange
{
    public:
    IterRange()
    :first_(nullptr), last_(nullptr)
    {

    }

    IterRange(iterator first, iterator last)
    : first_(first), last_(last)
    {
    
    }

    iterator first_;
    iterator last_;

    iterator begin()
    {
        return first_;
    }
    iterator end()
    {
        return last_;
    }
};

template<typename iter, typename callable>
class Map
{
    public:
    Map(IterRange<iter> iter_range, callable fn)
    :iter_range_(iter_range), fn_(fn)
    {

    }

    IterRange<iter> map()
    {
        iter temp = iter_range_.first_;
        while (temp != iter_range_.end())
        {
            *temp = fn_(*temp);
            ++temp;
        }
        return iter_range_;

    }

    IterRange<iter> iter_range_;
    callable fn_;

};


template<typename iter, typename callable>
class Filter
{
    public:
    Filter(IterRange<iter> iter_range, callable fn)
    :iter_range_(iter_range), curr_(iter_range_.first_), fn_(fn)
    {
        
    }

    Filter& operator++()
    {
        // std::cout << "Entered ++\n";
        if (curr_ == iter_range_.begin())
        {
            if (fn_(*curr_))
            {
                return *this;
            }
        }

        while (curr_ != iter_range_.end())
        {
            ++curr_;
            // std::cout << "Iteration #" << *curr_ << "\n";
            if (fn_(*curr_))
            {
                // std::cout << "This is what is returned " << *curr_ << "\n"; 
                return *this;
            }
        }
        return *this; 
    }

    Filter operator++(int)
    {
        Filter temp = *this;
        ++*this;
        return temp;
    }

    iter begin()
    {
        return iter_range_.first_;
    }
    iter end()
    {
        return iter_range_.last_;
    }
    iter current()
    {
        return curr_;
    }

    IterRange<iter> iter_range_;
    iter curr_;
    callable fn_;

};



int is_even(int x)
{
    if (x % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int square(int x)
{
    return x * x;
}

class Even
{
    public:
    bool operator()(int x){ return (x % 2 == 0);}
};

int main()
{
    std::vector<int> v1{1,2,3,4,5,6,7,8,9};
    std::list<int> l1{1,2,3,4,5,6,7,8,9};

    IterRange i1(v1.begin(), v1.end());

    Filter f1(i1, is_even);
    std::cout << *f1.current() << "\n";
    ++f1;
    std::cout << *f1.current() << "\n";
    ++f1;
    std::cout << *f1.current() << "\n";
    f1++;
    std::cout << *f1.current() << "\n";
    ++f1;
    std::cout << *f1.current() << "\n";

    for(auto it:v1)
    {
        std::cout << it << "\n";
    }

    Map m1(i1, square);
    IterRange i2 = m1.map();

    auto it = i2.begin();
    while (it != i2.end())
    {
        std::cout << *it << "\n";
        ++it;
    }

}
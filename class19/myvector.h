#ifndef MYVECTOR_H
#define MYVECTOR_H

//inner class: 
//  a) hide class
//      implementation class
//  b) implementation of inner class is associated with that of the outer class


class myvector
{
    public:
    explicit myvector(int n);
    ~myvector();
    //contextual keyword
    myvector(const myvector&) = delete;
    myvector& operator=(const myvector&) = delete;

    //class within a class
    //indicates a position 
    //opaque object 
    class myiterator
    {
        public:
        explicit myiterator(int *ptr = nullptr) : ptr_(ptr) { }
        int operator*() const{ return *ptr_;}
        bool operator==(const myiterator& rhs) const
        {
            return ptr_ == rhs.ptr_;
        }

        //canonical way of writing inequality logic at one place    
        //!= should call ==
        bool operator!=(const myiterator& rhs) const
        {
            return !(*this == rhs);
        }
        
        myiterator& operator++() //pre inc
        {
            ++ptr_;
            return *this;
        }
        myiterator operator++(int) //post inc
        {
            myiterator temp = *this;
            ++*this;
            return temp;
        }

        private:
        int *ptr_;
    };
    myiterator begin()
    {
        return myiterator(p_);
    }

    myiterator end()
    {
        return myiterator(p_ + n_);
    }

    private:
    int *p_;
    int n_;
};

#endif
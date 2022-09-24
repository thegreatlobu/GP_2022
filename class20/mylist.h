#ifndef MYLIST_H
#define MYLIST_H

class Node
{
    int key_;
    Node* link_;
    Node(int key)
    :key_(key), link_(nullptr)
    {
    }

    friend class mylist;
    
};

class mylist
{
    private:
    Node* head_;

    public:
    mylist();
    void insert(int);
    void disp() const;

    class iterator
    {
        public:
        explicit iterator(Node *ptr = nullptr) : ptr_(ptr) { }
        int operator*() const{ return ptr_->key_;}

        bool operator==(const iterator& rhs) const
        {
            return ptr_ == rhs.ptr_;
        }

        bool operator!=(const iterator& rhs) const
        {
            return !(*this == rhs);
        }
        
        iterator& operator++() 
        {
            ptr_ = ptr_->link_;
            return *this;
        }
        iterator& operator++(int) 
        {
           return ++*this;
        }

        private:
        Node *ptr_;
    };

    iterator begin()
    {
        return iterator(head_);
    }

    iterator end()
    {
        // Node* temp = head_;
        // while(temp)
        // {
        //     temp = temp->link_;
        // }
        return iterator(nullptr);
    }
  
};

#endif
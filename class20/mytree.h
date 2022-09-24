#ifndef MYTREE_H
#define MYTREE_H

class Node
{

    int key_;
    Node* parent_;
    Node* left_;
    Node* right_;
    Node(int key)
    :key_(key), parent_(nullptr), left_(nullptr), right_(nullptr)
    {
    }

    friend class mytree;
};

class mytree
{
    private:
    Node *root_;
    
    public:
    mytree();
    void insert(int);
    void inorder() const;
    void inorderhelper(Node* ptr) const;
  
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
            Node* succ = ptr_->parent_;
            Node* right_root = ptr_->right_;
            if(right_root)
            {
                while(right_root->left_)
                {
                    right_root = right_root->left_;
                }
                succ = right_root;
            }
            ptr_ = succ;
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
        Node* temp = root_;
        if(temp)
        {
            while(temp->left_)
            {
                temp = temp->left_;
            }
        }
        cout << temp->key_ << "\n";
        return iterator(temp);
    }

    iterator end()
    {
        return iterator(nullptr);
    }
};



#endif
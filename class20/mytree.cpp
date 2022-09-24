#include<iostream>
using namespace std;
#include "mytree.h"

mytree::mytree()
:root_(nullptr)
{
    
}

void mytree::insert(int key)
{
    if (root_ == nullptr)
    {
       Node* parent = new Node(-1);
       root_ = new Node(key);
       root_->parent_ = parent;
       return;
    }
    else
    {
        Node* cur = root_;
        Node* parent = nullptr;
        while (cur != nullptr)
        {
            parent = cur;
            if (key < cur->key_)
            {
                cur = cur->left_;
            }
            else
            {
                cur = cur->right_;
            }
        }

        if (key < parent->key_)
        {
            Node* newnode = new Node(key);
            parent->left_ = newnode;
            newnode->parent_ = parent;
            
        }
        else
        {
            Node* newnode = new Node(key);
            parent->right_ = newnode;
            newnode->parent_ = parent;
        }
    }
}

void mytree::inorder() const
{
   inorderhelper(root_);
}

void mytree::inorderhelper(Node *ptr) const
{
    if (ptr)
    {
        inorderhelper(ptr->left_);
        cout << "Node :" << ptr->key_  << "\t";
        inorderhelper(ptr->right_);
    }
    
}


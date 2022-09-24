#include<iostream>
using namespace std;
#include "list.h"

list::list()
:head_(nullptr)
{

}

void list::add(int key)
{
    Node* temp = new Node(key);
    //insert in beginning
    temp->link_ = head_;
    head_ = temp;

}

void list::disp() const
{
    Node* temp(head_);
    while(temp)
    {
        cout << temp->key_ << "\t";
        temp = temp->link_;
    }

}
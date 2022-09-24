#include <iostream>
using namespace std;
#include "mylist.h"

mylist::mylist()
:head_(nullptr)
{

}

void mylist::insert(int key)
{
    Node *temp = new Node(key);
    temp->link_ = head_;
    head_ = temp;
}

void mylist::disp() const
{
    Node* temp = head_;
    while(temp)
    {
        cout << temp->key_ << "\t";
        temp = temp->link_;
    }
    cout << "\n";
}
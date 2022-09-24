#ifndef LIST_H
#define LIST_H

class Node
{
    int key_;
    Node* link_;
    Node(int key)
    :key_(key), link_(nullptr)
    {
        
    }
    friend class list;
};

class list
{
    private:
    Node* head_;

    public:
    list();
    void add(int);
    void disp() const;
};

#endif
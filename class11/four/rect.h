#ifndef RECT_H
#define RECT_H

class Rect
{
private:
    int length_;
    int breadth_;

public:
    void read();
    void disp() const;
    int find_area() const;
    bool equal(const Rect&) const;
    //scales the length and breadth by a factor
    void scale(int sf);
    //create a new rect with length and breadth of the object interchanged; return it
    //do not change the object through which the call is made
    Rect transpose() const;
};

//equality:
//  referential semantics
//  value semantics

#endif
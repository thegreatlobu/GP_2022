#ifndef DATE_H
#define DATE_H

class date
{
    //trivial class(no allocation in ctor) so no need for dtor
    private:
    int dd_;
    int mm_;
    int yy_;

    public:
    date(int dd = 1, int mm = 1, int yy = 1970)
    : dd_(dd), mm_(mm), yy_(yy)
    {
    }
    friend ostream& operator<<(ostream& o, const date& d);
    friend bool operator<(const date& l, const date& r);
    date& operator++();
    date operator++(int);
};

#endif
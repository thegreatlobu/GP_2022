#ifndef PERSON_H
#define PERSON_H

struct person
{
    char name_[20];
    int age_;
    //implicit parameter
    //  will point to the variable thru which the fn is called
    //  parameter called: this
    void read_one(); //no explicit parameters
    void display() const; //constant member function, *this is a constant

};

/*

what is the effect of adding functions to structures?
-size of structures
-function call resolution

*/

#endif
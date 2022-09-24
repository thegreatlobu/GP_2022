#ifndef PERSON_H
#define PERSON_H

class person
{
private: //implementation
    char name_[20];
    int age_;

public: //interface
    void read_one(); 
    void display() const; 

};

//when is the access control checked?
//compile time

//what is the difference between structure and class?
//  default access- structure: every thing is public(interface)
//                  class: every thing is an private(implementation)

#endif
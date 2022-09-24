#ifndef PERSON_H
#define PERSON_H

class Person
{
    private:
    char* name_;
    int age_;

    public:
    void disp() const;
    Person(char*, int);
    //copy ctor
    //gets called when
    //initialization by object
    //passing paramateres by value
    //return by value
    Person(const Person&);
    Person& operator=(const Person& rhs);
    Person();
    ~Person();
};

//default ctor:
//  -ctor with no parameters
//  -ctor where every paramater has a default value

//copy assignment operator:
//  -compiler provides a default copy assignment operator.
//  -this does memberwise copy(Shallow copy)
//
//  -we can implement a copy assignment operator in a class
#endif
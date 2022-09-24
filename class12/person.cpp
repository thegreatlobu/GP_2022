#include<iostream>
using namespace std;
#include "person.h"
#include<cstring>
void Person::disp() const
{
    cout << name_ << "\t" << age_ << "\n";
}

Person::Person(char* name, int age)
:name_(new char[strlen(name) + 1]), age_(age)
{
    strcpy(name_, name);
}

Person::Person()
:name_(new char[1]), age_(0)
{
    strcpy(name_,""); //name[0] = '\0'
}

Person::~Person()
{
    delete[] name_;
}

#if 0
//assignment operator
void Person::operator=(const Person& rhs)
{
    //1. release the resource
    delete[] name_;
    //2. allocate resource
    name_ = new char[strlen(rhs.name_) + 1];
    //3. copy name
    strcpy(name_, rhs.name_);
    //4. copy age
    age_ = rhs.age_;
}
#endif

#if 0
//assignment op: with self assignment
void Person::operator=(const Person& rhs)
{
    if (this != &rhs)
    {
        //1. release the resource
        delete[] name_;
        //2. allocate resource
        name_ = new char[strlen(rhs.name_) + 1];
        //3. copy name
        strcpy(name_, rhs.name_);
        //4. copy age
        age_ = rhs.age_;
    }
}
#endif

//return obj to support cascading 
Person& Person::operator=(const Person& rhs)
{
    if (this != &rhs)
    {
        //1. release the resource
        delete[] name_;
        //2. allocate resource
        name_ = new char[strlen(rhs.name_) + 1];
        //3. copy name
        strcpy(name_, rhs.name_);
        //4. copy age
        age_ = rhs.age_;
    }
    return *this;
}

Person::Person(const Person& rhs)
: name_(new char[strlen(rhs.name_) + 1]), age_(rhs.age_)
{
    strcpy(name_, rhs.name_);
}

//can we call dtor explicitly
//will the object die if the dtor is called?
//will the dtor be called again if the object dies
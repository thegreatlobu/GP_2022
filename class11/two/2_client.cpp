#include<iostream>
using namespace std;
#include "2_person.h"

int main()
{
    person a;
    //structname::fname()
    //address of struct varaible through which the call is made is passed as first arguement, implicit arguement
    a.read_one(); //person::read_one(&a), :: scope resolution operator
    a.display();
}
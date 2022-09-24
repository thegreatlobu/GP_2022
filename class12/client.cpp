#include<iostream>
using namespace std;
#include "person.h"

int main()
{
    #if 0
    char name[] = "Amar";
    Person a(name, 20);
    a.disp();
    name[0] = ' ';
    a.disp(); //alias
    #endif
    
    char name[] = "Amar";
    Person a(name, 20);
    a.disp();
    name[0] = ' ';
    a.disp();

    Person b;
    b.disp();
    char name1[] = "chandra";
    Person c(name1, 18);
    c.disp();

    c = a; //c.operator=(a);
    c.disp();

    
}
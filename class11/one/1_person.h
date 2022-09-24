//avoid multiple inclusions of the header file
//guard 
#ifndef PERSON_H
#define PERSON_H
//definition of type for the compiler   
//decides the binary layout of a structure
//decides the total size of the structure
//decides position of each field
struct person
{
    char name_[20];
    int age_;
};

#if 0
void read_one(person&);
//parameter passing of a structure by value:
//  -takes more space
//  -takes more time cuz of copy
//  can lead to problems with pointers
//      -dangling ptrs
//      -alias
//      -garbage=>leak
//change a variable - pass by reference
//do not want to change - 
//  simple type - pass by value
//  structured type - pass by ref to const

void display(person);
#endif

//ver2
void read_one(person&);
void display(const person&);



//what goes to the header file is either for the compiler or it is totally consumed by the compiler and not given to the linker
#endif
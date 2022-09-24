#include<iostream>
using namespace std;
//macro processor does not know C/C++
//directives can come anywhere
//#define: causes text replacement in the text below and not above
//no  scope

//introduce the preprocessor symbol during compilation using flag -DE=50
#define A 10

int main()
{
    printf("A : %d\n", A);
    #define B 20
    printf("B : %d\n", B);

    int d = 40;
    {
        int d = 400;
        printf("d : %d\n", d); //400
    }
    printf("d : %d\n", d); //40
    #define A 100
    printf("A : %d\n", A); //100

    #define D 40
    {
        #define D 400
        printf("D : %d", D); //400
    }
    printf("D : %d", D); //400
}

//g++ -E filename - output of the preprocessor
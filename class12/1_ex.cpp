#include<iostream>
using namespace std;

class A
{
    public:
    A();
    ~A();
};

A::A()
{
    cout << "Constructor\n";
}

A::~A()
{
    cout << "Destructor\n";
}

int main()
{
    //A x;
    //A x[5];
    {
        cout <<"one\n";
        A x; //constr call
        {
            A& y = x; //no constr call
            A *p; //no const call
            p = new A; //constr call but no destr call
            // new operator: calls constr
            //  operator new for allocation of memory
            delete p;
            //delete operator: calls the destructor
            //  operator delete for deallocation of memory
        }
        cout << "two\n";
    }//destr call

}
#include<iostream>
using namespace std;
#include "rect.h"

int main()
{
    Rect r1;
    Rect r2;
    r1.read();
    r1.disp();
    // r2.read();
    // r2.disp();
    cout << "Area: " << r1.find_area() << "\n";
    // cout << boolalpha;
    // cout << "Equal: " << r1.equal(r2) << "\n";

    Rect r3;
    r3 = r1.transpose();
    r3.disp();
}
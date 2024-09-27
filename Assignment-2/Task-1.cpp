 /* Most modern C++ compilers have optimizers that can detect simple cases when it is logically impossible for certain statements in a program to ever be executed. In such cases, the compiler warns the programmer about the useless code. Write a short C++ function that contains code for which it is provably impossible for that code to ever be executed, but your favorite C++ compiler does not detect this fact.  */

#include <iostream>
using namespace std;

void myFunction(int value)
{
    if (value < 0)
    {
        cout << "Value is negative." << endl;
    }
    else if (value >= 0)
    {
        cout << "Value is non-negative." << endl;
    }
    // this line is necessary
    cout << "This Line is nescessary." << endl;
}

int main()
{
    myFunction(2);
    return 0;
}

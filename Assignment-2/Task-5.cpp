/* Write a C++ class that is derived from the Progression class to produce a progression where each value is the square root of the previous value. (Note that you can no longer represent each value with an integer.) You should include a default constructor that starts with 65,536 as the first value and a parametric constructor that starts with a specified (double) number as the first value.    */

#include <iostream>
#include <cmath> // For sqrt()

using namespace std;

// Base class for a generic progression
class Progression
{
protected:
    double first;   // First value of the progression
    double current; // Current value in the progression

public:
    // Default constructor initializes first value to 0
    Progression(double start = 0) : first(start), current(start) {}

    // Reset progression to first value
    void reset()
    {
        current = first;
    }

    // Get next value in the progression (pure virtual method)
    virtual double nextValue() = 0;

    // Print the first n values of the progression
    void printProgression(int n)
    {
        reset();
        cout << first << " "; // Print the first value
        for (int i = 1; i < n; i++)
        {
            cout << nextValue() << " ";
        }
        cout << endl;
    }
};

// Derived class to calculate progression based on square root of the previous value
class SqrtProgression : public Progression
{
public:
    // Default constructor: starts with 65,536
    SqrtProgression() : Progression(65536) {}

    // Parametric constructor: starts with specified first value
    SqrtProgression(double firstValue) : Progression(firstValue) {}

    // Override to calculate the next value as the square root of the current value
    virtual double nextValue() override
    {
        current = sqrt(current); // Update current to be the square root of the current value
        return current;
    }
};

int main()
{
    // Using the default constructor
    SqrtProgression prog1;
    cout << "Progression with default constructor (starting with 65,536):" << endl;
    prog1.printProgression(10); // Print first 10 values

    // Using the parametric constructor
    SqrtProgression prog2(1000);
    cout << "\nProgression with parametric constructor (starting with 1,000):" << endl;
    prog2.printProgression(10); // Print first 10 values

    return 0;
}

/* Write a C++ class that is derived from the Progression class to produce a progression where each value is the absolute value of the difference between the previous two values. You should include a default constructor that starts with 2 and 200 as the first two values and a parametric constructor that starts with a specified pair of numbers as the first two values.  */

#include <iostream>
#include <cmath> // for std::abs

using namespace std; // Moved here to avoid the need for 'std::' prefix

// Base class for a generic progression
class Progression
{
protected:
    long first;   // First value of the progression
    long current; // Current value in the progression

public:
    // Default constructor initializes first value to 0
    Progression(long start = 0) : first(start), current(start) {}

    // Reset progression to first value
    void reset()
    {
        current = first;
    }

    // Get next value in the progression (pure virtual method)
    virtual long nextValue() = 0;

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

// Derived class to calculate progression based on absolute difference
class AbsDiffProgression : public Progression
{
private:
    long second;   // Second value of the progression
    long previous; // Stores the value before the current one

public:
    // Default constructor: starts with 2 and 200
    AbsDiffProgression() : Progression(2), second(200), previous(200) {}

    // Parametric constructor: starts with specified first and second values
    AbsDiffProgression(long firstValue, long secondValue)
        : Progression(firstValue), second(secondValue), previous(secondValue) {}

    // Override to calculate the next value based on absolute difference
    virtual long nextValue() override
    {
        long next = abs(current - previous); // Compute absolute difference
        previous = current;                  // Update previous to current
        current = next;                      // Update current to next
        return current;
    }

    // Reset also needs to reset previous to second value
    void reset()
    {
        current = first;
        previous = second;
    }
};

int main()
{
    // Using the default constructor
    AbsDiffProgression prog1;
    cout << "Progression with default constructor (starting with 2, 200):" << endl;
    prog1.printProgression(10); // Print first 10 values

    // Using the parametric constructor
    AbsDiffProgression prog2(5, 15);
    cout << "\nProgression with parametric constructor (starting with 5, 15):" << endl;
    prog2.printProgression(10); // Print first 10 values

    return 0;
}

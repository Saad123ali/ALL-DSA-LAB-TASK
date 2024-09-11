#include <iostream>
using namespace std;

// function to perform linear search
int LinearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++) // loop iterate no. of size
    {
        if (arr[i] == target) // match the target
        {
            return i; // if targdt found then return index
        }
    }
    return -1; // retrun -1 if target not found
}
int main()
{
    while (true)
    {
        int array[10]; // array declarations of 10 elements
        int size, target;
        cout << "\n\tEnter the size of the array : ";
        cin >> size;
        cout << "\n\tEnter " << size << " elements : " << endl;
        for (int i = 0; i < size; i++) // get the element from user input
        {
            cin >> array[i];
        }
        size = sizeof(array) / sizeof(array[0]); // check the array size after user input

        cout << "\n\tEnter the target to search : ";
        cin >> target;                                  // get the target form the user
        int result = LinearSearch(array, size, target); // call the function

        if (result == -1) // check the condition nothing found
        {
            cout << "\n\tError! Target is not found !\n"; // error message
        }
        else
        {
            cout << "\n\tTarget " << target << " found at index " << result << "\n"; // successfully found message
        }
    }
}
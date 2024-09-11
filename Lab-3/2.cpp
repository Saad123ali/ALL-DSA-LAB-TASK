#include <iostream>
using namespace std;

// Binary search function
int BinarySearch(int arr[], int size, int target)
{
    int low = 0;             // for array left side index
    int high = size - 1;     // for array right side index
    while (low <= high)
    {
        int mid = (low + high) / 2; // Corrected for array middle index
        if (arr[mid] == target)     // if target in the middle of the array
        {
            return mid; // return the index
        }

        if (arr[mid] > target) // if target is less than the array middle
        {
            high = mid - 1; // decrement the array middle index
        }
        else
        {
            low = mid + 1; // increment the array middle index
        }
    }
    return -1; // return if target is out of range
}

int main()
{
    while (true)
    {
        int array[10]; // array declarations of 10 elements
        int size, target;
        cout << "\n\tEnter the size of the array (max 10): ";
        cin >> size;

        if (size > 10) // Handle if size exceeds array capacity
        {
            cout << "\n\tError! Size exceeds the capacity of 10 elements.\n";
            continue;
        }

        cout << "\n\tEnter " << size << " elements (sorted order): " << endl;
        for (int i = 0; i < size; i++) // get the element from user input
        {
            cin >> array[i];
        }

        cout << "\n\tEnter the target to search: ";
        cin >> target;                                   // get the target from the user
        int result = BinarySearch(array, size, target);  // call the function

        if (result == -1) // check the condition if nothing is found
        {
            cout << "\n\tError! Target is not found!\n"; // error message
        }
        else
        {
            cout << "\n\tTarget " << target << " found at index " << result << "\n"; // successfully found message
        }
    }
}

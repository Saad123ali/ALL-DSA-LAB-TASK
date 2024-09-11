/* An e-commerce website stores customer order IDs in a one-dimensional array. After every
transaction, the array is updated with the new order ID. The website wants to implement a feature to
search for a specific order ID in the array and determine its position. Write a function that performs
this search efficiently, assuming the array can have up to 1,000 orders.  */

#include <iostream>
using namespace std;

int binarySearch(int array[], int target, int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
        {
            return mid;
        }

        if (array[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{

    while (true)
    {
        int array[10] = {100, 102, 356, 432, 566, 122, 666, 222, 987, 345};
        int n = sizeof(array) / sizeof(array[0]);
        int target;
        cout << "\n\tEnter the order id for search : ";
        cin >> target;
        int position = binarySearch(array, target, n);
        if (position != -1)
        {
            cout << "\n\tThe order id " << target << " found at the position :  " << position + 1 << "\n";
        }
        else
        {
            cout << "\n\tThe order id not found.\n ";
        }
        char ch;
        cout << "\n\tDo you want to search again? : ";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
            break;
        }
    }

    return 0;
}
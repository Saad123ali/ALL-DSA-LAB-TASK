#include <iostream>
using namespace std;

// Function to perform binary search in a rotated array
int binarySearchInRotatedArray(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        // Check if the target is at mid
        if (arr[mid] == target)
        {
            return mid;
        }

        if(arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    // Target not found
    return -1;
}

int main()
{
    int n;

    // Get the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n]; // Array to store the elements

    // Get the array elements from the user
    cout << "Enter " << n << " elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    // Get the target element from the user
    cout << "Enter the target element to search for: ";
    cin >> target;

    // Perform binary search to find the target in the rotated array
    int result = binarySearchInRotatedArray(arr, n, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}

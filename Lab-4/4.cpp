#include <iostream>
using namespace std;

// Recursive function to perform binary search in a sorted array
int recursiveBinarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1; // Target not found
    }

    int mid = left + (right - left) / 2; // Calculate mid

    // Check if the target is at mid
    if (arr[mid] == target)
    {
        return mid;
    }

    if (target < arr[mid])
    {
        return recursiveBinarySearch(arr, left, mid - 1, target);
    }
    else
    {
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }
}

int main()
{
    int n;

    // Get the size of the array from the user
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[n]; // Array to store the elements

    // Get the array elements from the user
    cout << "Enter " << n << " elements of the sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    // Get the target element from the user
    cout << "Enter the target element to search for: ";
    cin >> target;

    // Perform recursive binary search to find the target in the sorted array
    int result = recursiveBinarySearch(arr, 0, n - 1, target);

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

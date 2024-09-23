// Two-pointer Approach:

// Time complexity: O(n log n) if sorting is needed; otherwise, O(n).
// Space complexity: O(1) as only two pointers are used.

#include <iostream>
#include <algorithm> // For sort()
using namespace std;

void twoPointerApproach(int arr[], int n, int target)
{
    sort(arr, arr + n); // Sorting the array
    int left = 0;
    int right = n - 1;

    cout << "Two-pointer Approach: " << endl;
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            ++left;
            --right;
        }
        else if (sum < target)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    twoPointerApproach(arr, n, target);
    return 0;
}

//Output below

// Two-pointer Approach: 
// Pair found: (2, 7)    
// Pair found: (3, 6)    
// Pair found: (4, 5) 
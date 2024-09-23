// Brute Force Approach:

// Time complexity: O(n²) because we are checking all possible pairs.
// Space complexity: O(1), as no extra space is used.

#include <iostream>
using namespace std;

void bruteForceApproach(int arr[], int n, int target)
{
    cout << "Brute Force Approach: " << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    bruteForceApproach(arr, n, target);
    return 0;
}


//Output below 

// Brute Force Approach: 
// Pair found: (2, 7)
// Pair found: (3, 6)
// Pair found: (4, 5)
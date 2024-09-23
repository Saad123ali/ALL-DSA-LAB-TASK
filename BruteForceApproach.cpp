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

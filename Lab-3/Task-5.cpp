#include <iostream>
using namespace std;

int main()
{
    int arr[6];
    cout << "Enter six integers : ";
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    bool isPalindrome = true;
    for (int i = 0; i < 6 / 2; i++)
    {
        if (arr[i] != arr[6 - 1 - i])
        {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
    {
        cout << "The all array is Palindrome." << endl;
    }
    else
    {
        cout << "The all array is not Palindrome." << endl;
    }

    return 0;
}
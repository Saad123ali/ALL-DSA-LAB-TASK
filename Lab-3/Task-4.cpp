// // TASK 4

#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index;
    cout << "Array before deletion : ";
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the index to delete (0 to 9): ";
    cin >> index;

    if (index < 0 || index >= 10)
    {
        cout << "Invalid index!" << endl;
    }
    else
    {
        for (int i = index; i < 9; i++)
        {
            arr[i] = arr[i + 1];
        }
    }

    cout << "Updated array after deletion: ";
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
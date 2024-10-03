// TASK 3

#include <iostream>
using namespace std;

int main() {
    int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array size is increased by 1 to accommodate the new element
    int element, index;

    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the index at which to insert the element (0 to 10): ";
    cin >> index;

    if (index < 0 || index > 10) {
        cout << "Invalid index!" << endl;
    } else {
        // Shifting elements to the right to make space for the new element
        for (int i = 10; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element; // Inserting the new element

        // Displaying the updated array
        cout << "Updated array: ";
        for (int i = 0; i < 11; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

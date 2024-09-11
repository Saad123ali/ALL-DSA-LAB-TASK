#include <iostream>
using namespace std;
int main() {
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the No. to search for: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "No. found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No. not found in the array." << endl;
    }
    delete[] arr;
    return 0;
}
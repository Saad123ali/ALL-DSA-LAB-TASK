#include <iostream>
#include <string>
using namespace std;

// Define a struct to store name and phone number
struct Contact
{
    string name;
    string phoneNumber;
};

// Function to perform linear search
int linearSearch(Contact contacts[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (contacts[i].name == target)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Recursive function to perform binary search
int binarySearch(Contact contacts[], int left, int right, string target)
{
    if (left > right)
    {
        return -1; // Target not found
    }

    int mid = (right + left) / 2; // Calculate mid

    if (contacts[mid].name == target)
    {
        return mid; // Target found at mid
    }

    if (target < contacts[mid].name)
    {
        return binarySearch(contacts, left, mid - 1, target); // Search in the left half
    }
    else
    {
        return binarySearch(contacts, mid + 1, right, target); // Search in the right half
    }
}

// Function to sort contacts by name using bubble sort
void sortContacts(Contact contacts[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (contacts[j].name > contacts[j + 1].name)
            {
                swap(contacts[j], contacts[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of contacts in the phone book: ";
    cin >> n;

    Contact contacts[n]; // Array to store contacts

    // Input contacts
    cout << "Enter the contacts (name and phone number):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Contact " << i + 1 << " Name: ";
        cin >> contacts[i].name;
        cout << "Enter Contact " << i + 1 << " Phone Number: ";
        cin >> contacts[i].phoneNumber;
    }

    string target;
    cout << "Enter the name to search for: ";
    cin >> target;

    // Linear search
    int linearResult = linearSearch(contacts, n, target);
    if (linearResult != -1)
    {
        cout << "Linear Search: " << target << " found with phone number \n";
        cout << "User Name :"<<contacts[linearResult].name <<"\n";
        cout << "Contact no. "<<contacts[linearResult].phoneNumber << " at index " << linearResult << endl;
    }
    else
    {
        cout << "Linear Search: " << target << " not found in the phone book." << endl;
    }

    // Sort contacts for binary search
    sortContacts(contacts, n);

    // Binary search
    int binaryResult = binarySearch(contacts, 0, n - 1, target);
    if (binaryResult != -1)
    {
        cout << "Binary Search: " << target << " found with phone number \n";
        cout << "User Name :"<<contacts[binaryResult].name <<"\n";
        cout<<"Contact no. :" << contacts[binaryResult].phoneNumber << " at index " << binaryResult << " (sorted list)." << endl;
    }
    else
    {
        cout << "Binary Search: " << target << " not found in the sorted phone book." << endl;
    }

    return 0;
}

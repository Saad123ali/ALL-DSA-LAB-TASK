// Compare Linked List and array performance for insertion and deletion in terms of time complexity.

#include <iostream>
using namespace std;

// Node class for linked list
class Node
{
public:
    int data;
    Node *next; // Pointer to the next node

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Linked list class
class Linked
{
private:
    Node *head; // Pointer to the head of the linked list

public:
    // Constructor to initialize the linked list
    Linked()
    {
        head = nullptr;
    }

    // Function to insert a new node at the end of the linked list
    void insertion(int val)
    {
        Node *newNode = new Node(val); // Create a new node with the given value

        // If the list is empty, set the new node as the head
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            // Traverse to the last node
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode; // Set the next pointer of the last node to the new node
        }
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position)
    {
        // If the list is empty
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // If the position is the head node (first node)
        if (position == 0)
        {
            Node *temp = head;
            head = head->next; // Move the head pointer to the next node
            delete temp;       // Delete the original head node
            cout << "\nHead node deleted.\n";
            return;
        }

        Node *temp = head;
        // Traverse the list to find the node before the position to delete
        for (int i = 0; i < position - 1 && temp->next != nullptr; ++i)
        {
            temp = temp->next;
        }

        // Check if the position is out of range
        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        // Delete the node at the given position
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next; // Update the link to skip the deleted node
        delete nodeToDelete;           // Free the memory of the deleted node
        cout << "\nNode at position " << position << " deleted.\n";
    }

    // Function to display the linked list
    void display()
    {
        Node *temp = head;

        // Traverse the list and print each node's value
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

// Function to insert elements into the array
void insertArray(int arr[], int &size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value " << i + 1 << " : ";
        cin >> arr[i];
    }
}

// Function to delete an element from an array at a specific position
void arrayDelete(int arr[], int &size, int position)
{
    if (position < 0 || position >= size)
    {
        cout << "\nInvalid position\n";
        return;
    }

    // Shift elements to the left to overwrite the deleted element
    for (int i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--; // Reduce the array size by 1
    cout << "\nElement deleted successfully\n";
}

// Function to display the elements of the array
void arrayDisplay(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function to perform linked list and array operations
int main()
{
    Linked list;    // Create a linked list object
    int n, del, value;
    int size = 0, b, pos;

    int choice;
    int arr[100]; // Array with a maximum capacity of 100

    while (true)
    {
        // Menu for Linked List and Array operations
        cout << "\n--- Linked List Operations ---\n";
        cout << "1. Insert (Linked List)\n2. Delete (Linked List)\n3. Display (Linked List)\n";
        cout << "\n--- Array Operations ---\n";
        cout << "4. Insert (Array)\n5. Delete (Array)\n6. Display (Array)\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            // Insert elements into the linked list
            cout << "Enter the number of elements you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter the value " << i + 1 << " : ";
                cin >> value;
                list.insertion(value);
            }
        }
        else if (choice == 2)
        {
            // Delete a node from the linked list
            cout << "\nPlease enter the index of the node you want to delete: ";
            cin >> del;
            list.deleteAtPosition(del);
        }
        else if (choice == 3)
        {
            // Display the linked list
            cout << "\nCurrent values in the list:\n";
            list.display();
        }
        else if (choice == 4)
        {
            // Insert elements into the array
            cout << "Enter the number of elements you want to insert into the array: ";
            cin >> size;
            insertArray(arr, size);
        }
        else if (choice == 5)
        {
            // Delete an element from the array
            cout << "\nPlease enter the index of the element you want to delete: ";
            cin >> pos;
            arrayDelete(arr, size, pos);
        }
        else if (choice == 6)
        {
            // Display the array
            arrayDisplay(arr, size);
        }
        else if (choice == 7)
        {
            // Exit the program
            cout << "Exiting...\n";
            break;
        }
        else
        {
            // Invalid choice
            cout << "\nInvalid choice!" << endl;
        }
    }

    return 0;
}

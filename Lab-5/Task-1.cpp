//  Write a program to create a Linked List by taking user input for 5 nodes. Perform insertion, deletion, and search operations.

#include <iostream>
using namespace std;

// Class representing a single node in the linked list
class Node
{
public:
    int data;    // Data stored in the node
    Node *next;  // Pointer to the next node

    // Constructor to initialize a node with a given value
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Class representing the linked list and its operations
class Linked
{
private:
    Node *head;  

public:
    // Constructor to initialize an empty list
    Linked()
    {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insertion(int val)
    {
        Node *newNode = new Node(val);  // Create a new node with the given value

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
            temp->next = newNode;  // Set the next pointer of the last node to the new node
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
            head = head->next;   // Move the head pointer to the next node
            delete temp;         // Delete the original head node
            cout << "\nHead node deleted.\n";
            return;
        }

        Node *temp = head;
        // Traverse the list to find the node before the position to delete
        for (int i = 0; i < position - 1 && temp->next != nullptr; ++i)
        {
            temp = temp->next;
        }

        // Check if position is out of range
        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        // Delete the node at the given position
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;  // Update the link to skip the deleted node
        delete nodeToDelete;            // Free the memory of the deleted node
        cout << "\nNode at position " << position << " deleted.\n";
    }

    // Function to search for a node at a specific index
    void search(int index)
    {
        bool found = false;
        Node *temp = head;
        int currPosition = 0;

        // Traverse the list to find the node at the given index
        while (temp != nullptr)
        {
            if (currPosition == index)
            {
                cout << "\nNode found at index " << index << " with value " << temp->data << "\n";
                found = true;
                break;
            }
            temp = temp->next;
            currPosition++;
        }

        // If the node was not found
        if (!found)
        {
            cout << "\nNode not found in the list\n";
        }
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

int main()
{
    Linked list;  // Create a linked list object
    int value, del, search;  

    // Inserting 5 nodes into the linked list
    cout << "Enter 5 values in the linked list:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter value " << i + 1 << " : ";
        cin >> value;
        list.insertion(value);  // Insert the value into the list
    }

    // Display the linked list
    cout << "\nThe values in the linked list are:\n";
    list.display();

    // Deleting a node at a specific position
    cout << "\nPlease enter the index you want to delete (0 - 4):\n";
    cin >> del;
    list.deleteAtPosition(del);

    // Display the linked list after deletion
    cout << "\nList after deleting the node:\n";
    list.display();

    // Searching for a node at a specific index
    cout << "\nPlease enter the index you want to search (0 - 3):\n";
    cin >> search;
    list.search(search);

    return 0;
}

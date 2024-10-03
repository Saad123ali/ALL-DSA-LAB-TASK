//  Implement a program to reverse a Singly Linked List.

#include <iostream>
using namespace std;

// Class representing a single node in the linked list
class Node
{
public:
    int data;    
    Node *next;  

    // Constructor to initialize the node with a value and set the next pointer to nullptr
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Class representing the linked list
class Linked
{
private:
    Node *head;  // Pointer to the head (first node) of the list

public:
    // Constructor to initialize an empty list (head is set to nullptr)
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
            // Traverse the list to find the last node
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            // Set the next pointer of the last node to the new node
            temp->next = newNode;
        }
    }

    // Function to reverse the linked list
    void reverse()
    {
        Node *prev = nullptr;   
        Node *current = head;   
        Node *next = nullptr;   

        // Loop through the list and reverse the links
        while (current != nullptr)
        {
            next = current->next;    // Save the next node before modifying the current node's link
            current->next = prev;    // Reverse the current node's link to point to the previous node
            prev = current;          // Move the previous pointer to the current node
            current = next;          // Move the current pointer to the next node
        }

        head = prev;  // After the loop, prev will point to the new head (last node of the original list)
    }

    // Function to display the linked list
    void display()
    {
        Node *temp = head;  // Temporary pointer to traverse the list

        // Loop through the list and print each node's data
        while (temp != nullptr)
        {
            cout << temp->data << "->";  // Print the current node's data
            temp = temp->next;           // Move to the next node
        }

        cout << "Null" << endl;  
    }
};

int main()
{
    Linked list; // object
    int value;   

    // Prompt the user to enter 5 values for the linked list
    cout << "Enter 5 values for the linked list:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;           // Read the user's input
        list.insertion(value);  // Insert the value into the linked list
    }

    // Display the original list
    cout << "\nOriginal List:\n";
    list.display();

    // Reverse the linked list
    list.reverse();

    // Display the reversed list
    cout << "\nReversed List:\n";
    list.display();

    return 0;   
}

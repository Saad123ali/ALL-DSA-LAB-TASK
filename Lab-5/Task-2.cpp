//  Implement a program to find the middle of a Linked List using a two-pointer approach (slow and fast pointer).

// Note: In a singly linked list, we can't move backward

#include <iostream>
using namespace std;

// Node class to represent each node of the linked list
class Node
{
public:
    int data;   // Data value of the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Linked List class
class LinkedList
{
private:
    Node *head; // Pointer to the head of the linked list

public:
    // Constructor to initialize the linked list
    LinkedList()
    {
        head = NULL;
    }

    // Function to insert a new node at the end of the linked list
    void insert(int val)
    {
        Node *newNode = new Node(val); // Create a new node with the given value

        if (head == NULL)
        {
            head = newNode; // If the list is empty, set the new node as the head
        }
        else
        {
            Node *temp = head;
            // Traverse to the end of the list
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode; // Insert the new node at the end
        }
    }

    // Function to find the middle element using the two-pointer (slow and fast) approach
    void findMiddle()
    {
        // If the list is empty, print a message and return
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *slow = head; // Slow pointer
        Node *fast = head; // Fast pointer

        // Move the fast pointer two steps and the slow pointer one step at a time
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // When the loop ends, the slow pointer will be at the middle of the list
        cout << "The middle element is: " << slow->data << endl;
    }

    // Function to display the elements of the linked list
    void display()
    {
        Node *temp = head;

        // Traverse the list and print each node's value
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

// Main function to test the program
int main()
{
    LinkedList list;
    int value, n;

    // Insert elements into the linked list
    cout << "Enter the number of elements you want to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    // Display the current linked list
    cout << "Current Linked List: ";
    list.display();

    // Find and display the middle element of the linked list
    list.findMiddle();

    return 0;
}

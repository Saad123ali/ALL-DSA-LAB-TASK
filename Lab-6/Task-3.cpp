/*
·   Implement and test the following scenarios:

o    Deleting from an empty list.

o    Inserting at a position greater than the length of the list.

o    Deleting all nodes one by one and trying further deletions.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    // Constructor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printList();
    }

    // Insert at the end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printList();
    }

    // Insert at a specific position
    void insertAtPosition(int pos, int val)
    {
        if (pos <= 0)
        {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1)
        {
            insertAtBeginning(val);
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (!temp)
        {
            cout << "Position out of bounds. Insertion failed.\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;

        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty. Deletion failed.\n";
            return;
        }

        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty. Deletion failed.\n";
            return;
        }

        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Delete from a specific position
    void deleteFromPosition(int pos)
    {
        if (pos <= 0 || !head)
        {
            cout << "Invalid position or empty list. Deletion failed.\n";
            return;
        }

        if (pos == 1)
        {
            deleteFromBeginning();
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp && count < pos)
        {
            temp = temp->next;
            count++;
        }

        if (!temp)
        {
            cout << "Position out of bounds. Deletion failed.\n";
            return;
        }

        if (temp->next)
            temp->next->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = temp->next;

        if (temp == tail)
            tail = temp->prev;

        delete temp;
    }

    // Print the list
    void printList()
    {
        Node *temp = head;
        if (!temp)
        {
            cout << "List is empty.\n";
            return;
        }
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Delete all nodes one by one
    void deleteAllNodes()
    {
        while (head)
        {
            deleteFromBeginning();
        }
        cout << "All nodes deleted.\n";
    }
};

int main()
{
    DoublyLinkedList dll;

    cout << "Test 1: Deleting from an empty list\n";
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteFromPosition(1);

    // Insert some elements
    cout << "\nInserting elements:\n";
    cout<<endl;
    cout<<"Insert elements in the beginnig of double linked list\n";
    dll.insertAtBeginning(10);
    cout<<"Insert elements at the end of double linked list\n";
    dll.insertAtEnd(20);
    cout<<"Insert elements at the end of double linked list\n";
    dll.insertAtEnd(30);

    cout << "Test 2: Inserting at a position greater than the length of the list\n";
    dll.insertAtPosition(5, 25);

    cout << "Test 3: Deleting all nodes one by one\n";
    dll.deleteAllNodes();
    dll.deleteFromBeginning();
    dll.deleteFromEnd();      
    dll.deleteFromPosition(1);

    return 0;
}

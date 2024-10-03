/*
 Implement a doubly linked list with the following features:

Insert at the beginning, end, and a specific position.

Delete nodes from the beginning, end, and a specific position.

Test the operations by printing the list after each modification.
  */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

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
            cout << "Position out of bounds.\n";
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
        printList();
    }

    // Delete from the beginning
    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty.\n";
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
        printList();
    }

    // Delete from the end
    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty.\n";
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
        printList();
    }

    // Delete from a specific position
    void deleteFromPosition(int pos)
    {
        if (pos <= 0 || !head)
        {
            cout << "Invalid position or empty list.\n";
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
            cout << "Position out of bounds.\n";
            return;
        }

        if (temp->next)
            temp->next->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = temp->next;

        if (temp == tail)
            tail = temp->prev;

        delete temp;
        printList();
    }

    // Print the list
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList dll;

    cout<<"Insert at the beginning of the list"<<endl;
    dll.insertAtBeginning(10);
    cout<<"Insert at the end of the list"<<endl;
    dll.insertAtEnd(20);
    cout<<"Insert at the end of the list"<<endl;
    dll.insertAtEnd(30);
    cout<<"Insert at the Specific position of the list"<<endl;
    dll.insertAtPosition(2, 15);
    cout<<"Insert at the Specific position of the list"<<endl;
    dll.insertAtPosition(5, 35);

    // Test deletions
    cout<<"Delete form the beginning of the list"<<endl;
    dll.deleteFromBeginning();
    cout<<"Delete form the end of the list"<<endl;
    dll.deleteFromEnd();
    cout<<"Delete form the specific position of the list"<<endl;
    dll.deleteFromPosition(2);

    return 0;
}

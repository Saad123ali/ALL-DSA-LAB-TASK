/*
Write a function that returns the middle element of a doubly linked list
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

    void insert(int val)
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
    }

    void findMiddleNode()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle node: " << slow->data << endl;
    }

    // Print the list
    void print()
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

    int value;
    cout<<"Enter five elements in the double linked list."<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"Enter value: "<<i+1<<" : ";
        cin>>value;
        dll.insert(value);
    }

    dll.print();
    dll.findMiddleNode();

    return 0;
}

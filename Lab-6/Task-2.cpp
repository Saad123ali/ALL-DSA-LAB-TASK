/*
Write a program to traverse a doubly linked list in both forward and backward directions. Insert at least 5 nodes and demonstrate forward and backward traversal.
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

    void traversal()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseTraversal()
    {
        if (!tail)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = tail;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    int value;
    cout<<"Enter five elements in the list"<<endl;
    for(int i= 0; i<5; i++)
    {
        cout<<"Enter value "<<i+1<<" : ";
        cin>>value;
        list.insert(value);
    }

    cout<<"Traversal the double list"<<endl;
    list.traversal();
    cout<<"Traversal reverse the double list"<<endl;
    list.reverseTraversal();
    
}
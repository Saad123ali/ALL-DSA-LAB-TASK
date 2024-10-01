#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Linked
{
private:
    Node *head;

public:
    Linked() : head(nullptr) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

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
                cout << "\nThe middle of linked list " << temp->data << "\n";
                found = true;
                break;
            }
            temp = temp->next;
            currPosition++;
        }

    }

    void display()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;;
        }
        cout<<"Null"<<endl;
    }
};

int main()
{
    Linked list;
    int value , n, count = 0;

    cout<<"How many elements do you want to enter? ";
    cin>>n;
    for( int i = 0; i < n; i++ )
    {
        cout<<"Enter the value"<<i+1<<" : ";
        cin>>value;
        list.insert(value);
        count++;
    }
    

    list.display();

    list.search(count/2);

    return 0;
}
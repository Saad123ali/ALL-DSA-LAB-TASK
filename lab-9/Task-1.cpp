/*
Write a program of linear linked list to implement a queue of objects of “person” class. Attributes of “person” class (privately defined) are per_id (int), per_name (string) and per_age (int). “person” class contains member functions (publicly defined): constructor, input and output functions. You are required to define one more class define the linked list implementation of queue for objects of “person” class, this class should contain the member functions like addQueue, RemoveQueue and check whether the queue is empty or not?
*/

#include <iostream>
using namespace std;

class person
{
private:
    int per_id;
    string per_name;
    int per_age;

public:
    person() : per_id(0), per_name(""), per_age(0) {}

    void input()
    {
        cout << "\nEnter person id" << endl;
        cin >> per_id;
        cout << "\nEnter person name" << endl;
        cin.ignore();
        getline(cin, per_name);
        cout << "\nEnter person age" << endl;
        cin >> per_age;
    }

    void output()
    {
        cout << "\nPerson details\n" << endl;

        cout << "\nEnter person id" << per_id << endl;
        cout << "\nEnter person name" << per_name << endl;
        cout << "\nEnter person age" << per_age << endl;
    }
};

// Node class representing each node of the linked list
class Node
{
public:
    person data; // Object of person class
    Node *next;  // Pointer to the next node

    Node(person p) : data(p), next(nullptr) {}
};

// Queue class that uses a linked list to implement a queue
class Queue
{
private:
    Node *front; // same as heade
    Node *rear;  // same as tail

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to add (enqueue) a person to the queue
    void addQueue(person p)
    {
        Node *newNode = new Node(p);

        if (isEmpty())
        {
            // If the queue is empty, both front and rear point to the new node
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Person added to the queue!\n";
    }

    // Function to remove (dequeue) a person from the queue
    person removeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot remove any person.\n";
            return person();
        }
        else
        {
            Node *temp = front;
            person p = front->data;
            front = front->next;

            // If front becomes null, set rear to null as well (empty queue)
            if (front == nullptr)
            {
                rear = nullptr;
            }

            delete temp;
            cout << "Person removed from the queue!\n";
            p.output();
            return p;
        }
    }

    // Function to display the queue
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }

        Node *temp = front;
        while (temp != nullptr)
        {
            temp->data.output();
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q;
    int choice;

    while(true)
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Add a person to the queue\n";
        cout << "2. Remove a person from the queue\n";
        cout << "3. Display the queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            person p;
            p.input();
            q.addQueue(p);
        }
        else if (choice == 2)
        {
            q.removeQueue();
        }
        else if (choice == 3)
        {
            q.displayQueue();
        }
        else if (choice == 4)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    } 

    return 0;
}
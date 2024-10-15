/*
Write a program which should contain two queues of link list of size 5 each, elements of link list should be of integer (int) type. User will insert values at rear of first queue, when a value will be removed from front of first queue it should be inserted at rear of second queue. For each queue you have to check queue overflow and underflow conditions. User may remove an element from front of second queue as well.
*/

#include <iostream>
using namespace std;

// Node class for linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue
{
private:
    Node *front;
    Node *rear;
    int size;
    int MAX_SIZE;

public:
    // Constructor to initialize queue with max size
    Queue(int maxSize) : front(nullptr), rear(nullptr), size(0), MAX_SIZE(maxSize) {}

    // Function to check if the queue is full
    bool isFull()
    {
        return size == MAX_SIZE;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Function to enqueue an element at the rear of the queue
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << val << "!" << endl;
            return;
        }

        Node *newNode = new Node(val);
        if (rear == nullptr)
        {
            // If the queue is empty, both front and rear will point to the new node
            front = rear = newNode;
        }
        else
        {
            // Otherwise, insert at the rear and update the rear pointer
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Enqueued: " << val << endl;
    }

    // Function to dequeue an element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue!" << endl;
            return -1;
        }

        Node *temp = front;
        int val = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            // If front becomes null, set rear to null (empty queue)
            rear = nullptr;
        }

        delete temp;
        size--;
        cout << "Dequeued: " << val << endl;
        return val;
    }

    // Function to display the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1(5); // First queue with max size of 5
    Queue q2(5); // Second queue with max size of 5

    int choice, value;

    while (true)
    {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue in Queue 1\n";
        cout << "2. Dequeue from Queue 1 and Enqueue to Queue 2\n";
        cout << "3. Dequeue from Queue 2\n";
        cout << "4. Display Queue 1\n";
        cout << "5. Display Queue 2\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value to enqueue in Queue 1: ";
            cin >> value;
            q1.enqueue(value);
        }
        else if (choice == 2)
        {
            if (!q1.isEmpty())
            {
                value = q1.dequeue();
                if (value != -1)
                {
                    q2.enqueue(value);
                }
            }
            else
            {
                cout << "Queue 1 is empty. Cannot dequeue and transfer!" << endl;
            }
        }
        else if (choice == 3)
        {
            q2.dequeue();
        }
        else if (choice == 4)
        {
            cout << "Queue 1: ";
            q1.display();
        }
        else if (choice == 5)
        {
            cout << "Queue 2: ";
            q2.display();
        }
        else if (choice == 6)
        {
            cout << "Exiting..." << endl;
            return 0;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

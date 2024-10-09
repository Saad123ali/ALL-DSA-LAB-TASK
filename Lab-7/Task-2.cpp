// Implement a function to insert a node at the beginning of the circular linked list.
// Ensure that the circular nature of the list is preserved.

#include <iostream>
using namespace std;

// Node structure for Circular Linked List
class Node {
public:
    int data;   // Data of the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head; // Head pointer to the first node

public:
    // Constructor to initialize the list
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the circular linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // If the list is empty, initialize head and point it to itself
            head = newNode;
            newNode->next = head;
        } else {
            // If the list is not empty, find the last node and insert the new node
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Point the new node back to the head to complete the circle
        }
    }

    // Function to insert a node at the beginning of the circular linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // If the list is empty, initialize head and point it to itself
            head = newNode;
            newNode->next = head;
        } else {
            // If the list is not empty, find the last node
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            // Point the last node's next to the new node
            temp->next = newNode;
            // Set new node's next to current head
            newNode->next = head;
            // Update head to the new node
            head = newNode;
        }
    }

    // Function to traverse and print the elements of the circular linked list
    void printList() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    // Create an empty circular linked list
    CircularLinkedList cll;

    // Insert some nodes at the end
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    // Traverse and print the list
    cout << "Circular Linked List after inserting at the end: ";
    cll.printList();

    // Insert node at the beginning
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(5);

    // Traverse and print the list after insertion at the beginning
    cout << "Circular Linked List after inserting at the beginning: ";
    cll.printList();

    return 0;
}

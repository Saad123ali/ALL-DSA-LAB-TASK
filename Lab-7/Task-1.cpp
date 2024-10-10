// Create a Node structure to represent a node in the circular linked list.
// Implement a function to insert nodes at the end of the circular linked list.
// Implement a function to traverse and print the elements of the circular linked list.


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
    void insertNode(int value) {
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

    // Insert some nodes
    cll.insertNode(10);
    cll.insertNode(20);
    cll.insertNode(30);
    cll.insertNode(40);

    // Traverse and print the list
    cout << "Circular Linked List: ";
    cll.printList();

    return 0;
}

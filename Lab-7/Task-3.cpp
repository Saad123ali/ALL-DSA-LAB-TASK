// Implement a function to delete a node from the circular linked list by value.
// Ensure that the circular nature is maintained even after node deletion.

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

    // Function to delete a node from the circular linked list by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Check if the node to be deleted is the head node
        if (temp->data == value) {
            // If there's only one node
            if (temp->next == head) {
                delete head; // Delete the node
                head = nullptr; // Set head to nullptr
            } else {
                // Find the last node
                while (temp->next != head) {
                    temp = temp->next;
                }
                // Update the last node's next to the second node
                temp->next = head->next; 
                delete head; // Delete the old head
                head = temp->next; // Update head to the new first node
            }
            return;
        }

        // Search for the node to be deleted
        prev = head;
        temp = head->next;
        while (temp != head) {
            if (temp->data == value) {
                prev->next = temp->next; // Bypass the node to be deleted
                delete temp; // Delete the node
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Node with value " << value << " not found." << endl;
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
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(5);

    // Print the circular linked list
    cout << "Circular Linked List: ";
    cll.printList();

    // Delete a node (e.g., delete head)
    cll.deleteNode(5);
    cout << "After deleting 5: ";
    cll.printList();

    // Delete a node from the middle
    cll.deleteNode(30);
    cout << "After deleting 30: ";
    cll.printList();

    // Delete a node (e.g., delete tail)
    cll.deleteNode(40);
    cout << "After deleting 40: ";
    cll.printList();

    // Delete the last remaining node
    cll.deleteNode(10);
    cout << "After deleting 10: ";
    cll.printList();

    // Attempt to delete from an empty list
    cll.deleteNode(20); // This should indicate that the list is empty now

    return 0;
}

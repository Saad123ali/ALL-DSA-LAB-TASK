/*
Write a program which should implement a stack using a dynamic array, whose size will provided by user at program execution time. Elements of array used for stack are objects of―student‖  class.  ―student‖  class  contains  attributes  (privately  defined)  reg_no(int),  st_name (string)  and  cgpa   (float).  ―student‖   class  should  also   contain  member   functions  (publicly defined);  constructor,  input  and  output  functions.  User  will  push  objects  of  class  ―student‖, values of attributes of objects will be provided by user. When an object will be popped from stack, value of its attributes should be displayed on screen
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    // Default constructor to initialize attributes
    Student() : reg_no(0), st_name(""), cgpa(0.0) {}

    // Input function to take student details
    void input() {
        cout << "\nEnter the student registration number: ";
        cin >> reg_no;
        cin.ignore(); // To handle the newline character after entering reg_no
        cout << "Enter the student name: ";
        getline(cin, st_name);
        cout << "Enter the student CGPA: ";
        cin >> cgpa;
    }

    // Output function to display student details
    void output() const {
        cout << "\nStudent Details:\n";
        cout << "Registration Number: " << reg_no << "\n";
        cout << "Name: " << st_name << "\n";
        cout << "CGPA: " << cgpa << "\n";
    }
};

class Stack {
private:
    Student* students; // Dynamic array to hold students
    int top;
    int capacity;

public:
    // Constructor to allocate memory and initialize the stack
    Stack(int size) {
        students = new Student[size];
        top = -1;
        capacity = size;
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] students;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Push a student object onto the stack
    void push(const Student& s) {
        if (isFull()) {
            cout << "\nStack is full! Cannot push more students.\n";
        } else {
            students[++top] = s;
            cout << "\nStudent added to the stack.\n";
        }
    }

    // Pop a student object from the stack
    Student pop() {
        if (isEmpty()) {
            cout << "\nStack is empty! Cannot pop any students.\n";
            return Student(); // Return a default Student object
        } else {
            cout << "\nPopping a student from the stack:\n";
            students[top].output();
            return students[top--];
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size); // Create a stack with dynamic size

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push a Student\n";
        cout << "2. Pop a Student\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (!stack.isFull()) {
                Student s;
                s.input();
                stack.push(s);
            } else {
                cout << "Stack is full!\n";
            }
        } else if (choice == 2) {
            if (!stack.isEmpty()) {
                stack.pop();
            } else {
                cout << "Stack is empty!\n";
            }
        } else if (choice == 3) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

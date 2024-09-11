/* You are developing a library management system. The system needs to keep track of the number of
copies available for 100 different books in a library. How would you use an array to store the available
copies of each book? Implement a solution that initializes this array, adds a new book with 5 copies,
and updates the number of copies when a book is borrowed or returned. */

#include <iostream>
using namespace std;

void addBook(int bookArray[][2], int bookId, int id, int maxbook)
{
    if (id == maxbook)
    {
        cout << "\n\tNo more books added\n";
    }
    else
    {
        bookArray[id][0] = bookId;
        bookArray[id][1] = 5;
        id++;
        cout << "\n\tBook added successfully\n";
    }
}
void borrowBook(int bookArray[][2], int bookId, int maxBook)
{
    bool flag = false;
    for (int i = 0; i < maxBook; i++)
    {
        if (bookArray[i][0] == bookId)
        {
            if (bookArray[i][1] > 0)
            {
                bookArray[i][1]--;
                cout << "\n\tBook borrowed successfully\n";
            }
            else
            {
                cout << "\n\tNo copies available\n";
            }
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << "\n\tBook not found\n";
    }
}
void returnBook(int bookArray[][2], int bookId, int maxBooks)
{
    bool flag = false;
    for (int i = 0; i < maxBooks; i++)
    {
        if (bookArray[i][0] == bookId)
        {
            bookArray[i][1]++;
            cout << "\n\tBook returned successfully\n";
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << "\n\tBook Details not found\n";
    }
}
void displayBook(int bookArray[][2], int maxBook)
{
    cout << "\n\tBook ID \tAvailable Copies\n";
    for (int i = 0; i < maxBook; i++)
    {
        if (bookArray[i][0] != 0) 
        {
            cout << "\t" << bookArray[i][0] << "\t\t" << bookArray[i][1] << "\n";
        }
    }
}

int main()
{
    int maxBooks = 100;
    int id = 0;
    int bookId = 0;
    int BOOKS[maxBooks][2] = {0};
    string choice;
    while (true)
    {
        cout << "\n\tLibrary Management system\n\n";
        cout << "\t1. Add Book\n";
        cout << "\t2. Borrow Book\n";
        cout << "\t3. Return Book\n";
        cout << "\t4. Display Books\n";
        cout << "\t5. Exit\n";

        cout << "\n\tEnter your choice : ";
        cin >> choice;
        if (choice == "1")
        {
            cout << "\n\tEnter the book id to add : ";
            cin >> bookId;
            addBook(BOOKS, bookId, id, maxBooks);
        }
        else if (choice == "2")
        {
            cout << "\n\tEnter the book id to borrow : ";
            cin >> bookId;
            borrowBook(BOOKS, bookId, maxBooks);
        }
        else if (choice == "3")
        {
            cout << "\n\tEnter the book id to return : ";
            cin >> bookId;
            returnBook(BOOKS, bookId, maxBooks);
        }
        else if (choice == "4")
        {
            displayBook(BOOKS, maxBooks);
        }
        else if (choice == "5")
        {
            cout << "\n\tThanks for using this code...\n";
            break;
        }
        else
        {
            cout << "\n\tInvalid choice\n";
        }
    }

    return 0;
}
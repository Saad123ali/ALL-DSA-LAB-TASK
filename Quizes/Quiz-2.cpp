#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 5;  // Maximum number of books available in the store
const int MAX_PURCHASES = 5;  // Maximum number of books a user can purchase

// Book class to store details about books
class Book {
public:
    string title;
    string author;
    double price;

    Book() {}
    Book(string t, string a, double p) : title(t), author(a), price(p) {}
};

// User class to store purchased books
class User {
public:
    string username;
    Book purchasedBooks[MAX_PURCHASES];
    int purchaseCount;

    User(string name) : username(name), purchaseCount(0) {}

    void purchaseBook(Book book) {
        if (purchaseCount < MAX_PURCHASES) {
            purchasedBooks[purchaseCount] = book;
            purchaseCount++;
            cout << "You purchased: " << book.title << " by " << book.author << " for $" << book.price << endl;
        } else {
            cout << "You have reached the maximum number of purchases!" << endl;
        }
    }

    void viewPurchases() {
        if (purchaseCount == 0) {
            cout << "No books purchased yet." << endl;
        } else {
            cout << "Purchased books: " << endl;
            for (int i = 0; i < purchaseCount; ++i) {
                cout << purchasedBooks[i].title << " by " << purchasedBooks[i].author << " - $" << purchasedBooks[i].price << endl;
            }
        }
    }
};

// BookStore class to manage book listings and sales
class BookStore {
public:
    Book books[MAX_BOOKS];
    int bookCount;

    BookStore() : bookCount(0) {}

    void addBook(Book book) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount] = book;
            bookCount++;
        } else {
            cout << "BookStore is full, cannot add more books." << endl;
        }
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books available in the store." << endl;
        } else {
            cout << "Available Books: " << endl;
            for (int i = 0; i < bookCount; ++i) {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << " - $" << books[i].price << endl;
            }
        }
    }

    Book buyBook(int index) {
        if (index < 1 || index > bookCount) {
            cout << "Invalid book selection!" << endl;
            return Book("", "", 0);
        } else {
            return books[index - 1];
        }
    }
};

int main() {
    // Create a bookstore and add some books
    BookStore store;
    store.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 10.99));
    store.addBook(Book("1984", "George Orwell", 8.99));
    store.addBook(Book("To Kill a Mockingbird", "Harper Lee", 12.99));
    store.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 9.99));
    store.addBook(Book("Moby Dick", "Herman Melville", 11.49));

    // Create a user
    User user("John");

    int choice;
    do {
        cout << "\n--- Book Management System ---" << endl;
        cout << "1. Display available books" << endl;
        cout << "2. Buy a book" << endl;
        cout << "3. View purchase history" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.displayBooks();
                break;

            case 2: {
                store.displayBooks();
                cout << "Enter the book number you want to buy: ";
                int bookIndex;
                cin >> bookIndex;
                Book purchasedBook = store.buyBook(bookIndex);
                if (!purchasedBook.title.empty()) {
                    user.purchaseBook(purchasedBook);
                }
                break;
            }

            case 3:
                user.viewPurchases();
                break;

            case 4:
                cout << "Thank you for using the Book Management System!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

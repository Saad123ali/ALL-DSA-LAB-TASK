/*    Make a program to make the seating arrangement that have 15 rows and each of the rows have 15 seats and show that ( 1 ) is available and ( 0 ) is  unavailable and performe these task with 2d array
Display the all seats available and unavalable
2. User Book the seat
3. if Seat is already book then display message is unavailable
*/

#include <iostream>
#include <ctime>   

using namespace std;

const int ROWS = 10;
const int COLS = 15;

void displaySeats(int seats[ROWS][COLS]) {
    cout << "Current Seat Availability:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << "\n";
    }
}

bool bookSeat(int seats[ROWS][COLS], int row, int col) {
    if (seats[row][col] == 1) {
        seats[row][col] = 0; // Mark as booked
        return true;
    } else {
        return false;
    }
}

int main() {
    int seats[ROWS][COLS];

    // Initialize the random number generator
    srand(time(0));

    // Initialize seats randomly as available (1) or occupied (0)
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            seats[i][j] = rand() % 2; // Randomly assign 0 or 1
        }
    }

    int row, col;
    char choice;

    do {
        displaySeats(seats);

        cout << "Enter row (0-9) and column (0-14) to book a seat: ";
        cin >> row >> col;

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            if (bookSeat(seats, row, col)) {
                cout << "Seat successfully booked.\n";
            } else {
                cout << "Seat already booked.\n";
            }
        } else {
            cout << "Invalid row or column.\n";
        }

        cout << "Do you want to book another seat? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Final Seat Availability:\n";
    displaySeats(seats);

    return 0;
}

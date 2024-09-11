/* You are tasked with creating a seating arrangement system for a cinema. The cinema has 10 rows
with 15 seats in each row. Represent this seating arrangement using a two-dimensional array where
each seat can be marked as `1` (occupied) or `0` (available). Write a program to:
- Display the seating arrangement.
- Allow users to book a seat by marking it as occupied.
- Prevent users from booking an already occupied seat. */

#include <iostream>
#include <ctime>

using namespace std;

const int ROWS = 10;
const int COLS = 15;

void displaySeats(int seats[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << seats[i][j] << " ";
        }
        cout << "\n";
    }
}

bool bookSeat(int seats[ROWS][COLS], int row, int col)
{
    if (seats[row][col] == 0)
    {
        seats[row][col] = 1; 
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int seats[ROWS][COLS];

    srand(time(0));

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            seats[i][j] = rand() % 2; 
        }
    }

    int row, col;
    char choice;

    cout << "Current Seat Availability:\n";
    displaySeats(seats);

    cout << "Enter row (0-9) and column (0-14) to book a seat: ";
    cin >> row >> col;

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        if (bookSeat(seats, row, col))
        {
            cout << "Seat successfully booked.\n";
        }
        else
        {
            cout << "Seat already booked.\n";
        }
    }
    else
    {
        cout << "Invalid row or column.\n";
    }

    displaySeats(seats);

    return 0;
}

/* A university uses a one-dimensional array to store the grades of students in a particular course. The
university wants to implement a system that:
- Calculates the average grade for the course.
- Identifies how many students scored above and below the average.
- Finds and displays the highest and lowest grades in the class.  */

#include <iostream>
using namespace std;

int main()
{
    int students = 5;
    int grades[students] = {0};
    int sum = 0;
    int highest = 0, lowest = 100;

    for (int i = 0; i < students; i++)
    {
        cout << "\n\tEnter the grade of student : " << i + 1 << " : ";
        cin >> grades[i];
        sum += grades[i];

        if (grades[i] > highest)
        {
            highest = grades[i];
        }
        if (grades[i] < lowest)
        {
            lowest = grades[i];
        }
    }

    double average = static_cast<double>(sum) / students;
    int aboveCount = 0, belowCount = 0;
    for (int i = 0; i < students; i++)
    {
        if (grades[i] > average)
        {
            aboveCount++;
        }
        else if (grades[i] < average)
        {
            belowCount++;
        }
    }
    cout<<endl;
    cout << "Average grade: " << average << endl;
    cout << "Number of students above average: " << aboveCount << endl;
    cout << "Number of students below average: " << belowCount << endl;
    cout << "Highest grade: " << highest << endl;
    cout << "Lowest grade: " << lowest << endl;

    return 0;
}
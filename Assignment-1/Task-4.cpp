/* A temperature monitoring system records hourly temperatures for an entire week and stores them in 
a two-dimensional array where rows represent days and columns represent hours (24 hours per day). 
Write a program to:
- Calculate the average temperature for each day.
 - Identify the hour with the highest temperature for the entire week. 
 - Find out which day had the lowest average temperature. */


#include <iostream>
using namespace std;

int main()
{

    int DAYS = 7;
    int HOURS = 24;
    double temperatures[DAYS][HOURS];

    cout << "Enter temperatures for each hour of the week (7 days, 24 hours per day):\n";
    for (int i = 0; i < DAYS; i++)
    {
        cout << "Day " << i + 1 << ":\n";
        for (int j = 0; j < HOURS; j++)
        {
            cout << "  Hour " << j + 1 << ": ";
            cin >> temperatures[i][j];
        }
    }

    double dailyAverages[DAYS];
    for (int i = 0; i < DAYS; i++)
    {
        double sum = 0;
        for (int j = 0; j < HOURS; j++)
        {
            sum += temperatures[i][j];
        }
        dailyAverages[i] = sum / HOURS;
        cout << "Average temperature for Day " << i + 1 << ": " << dailyAverages[i] << endl;
    }

    double maxTemp = temperatures[0][0];
    int maxDay = 0, maxHour = 0;
    for (int i = 0; i < DAYS; i++)
    {
        for (int j = 0; j < HOURS; j++)
        {
            if (temperatures[i][j] > maxTemp)
            {
                maxTemp = temperatures[i][j];
                maxDay = i;
                maxHour = j;
            }
        }
    } 
    cout << "Highest temperature recorded is " << maxTemp << " on Day " << maxDay + 1 << " at Hour " << maxHour + 1 << "." << endl;

    double minAverage = dailyAverages[0];
    int minDay = 0;
    for (int i = 0; i < DAYS; i++)
    {
        if (dailyAverages[i] < minAverage)
        {
            minAverage = dailyAverages[i];
            minDay = i;
        }
    }
    cout << "Day " << minDay + 1 << " had the lowest average temperature of " << minAverage << "." << endl;

    return 0;
}

/* Make a program in 2d array that take data from the user of one week all the days and hours temperatures tell the average of each days and hours seperately nad also average of one week and last tell the highest and lowest temperature in one week day */

#include <iostream>
using namespace std;

int main() {
    const int DAYS = 7;   
    const int HOURS = 24; 

    double temperatures[DAYS][HOURS]; 
    double dayAverages[DAYS] = {0};   
    double hourAverages[HOURS] = {0}; 
    double weeklySum = 0;             
    double maxTemp = -1000, minTemp = 1000; 
    int maxDay = 0, minDay = 0;       

    for (int day = 0; day < DAYS; ++day) {
        for (int hour = 0; hour < HOURS; ++hour) {
            cout << "Enter temperature for Day " << day + 1 << ", Hour " << hour << ": ";
            cin >> temperatures[day][hour];

            dayAverages[day] += temperatures[day][hour];
            hourAverages[hour] += temperatures[day][hour];

            weeklySum += temperatures[day][hour];

            if (temperatures[day][hour] > maxTemp) {
                maxTemp = temperatures[day][hour];
                maxDay = day;
            }
            if (temperatures[day][hour] < minTemp) {
                minTemp = temperatures[day][hour];
                minDay = day;
            }
        }

        dayAverages[day] /= HOURS;
    }

    for (int hour = 0; hour < HOURS; ++hour) {
        hourAverages[hour] /= DAYS;
    }

    double weeklyAverage = weeklySum / (DAYS * HOURS);

    cout << "\nAverage Temperature for Each Day:\n";
    for (int day = 0; day < DAYS; ++day) {
        cout << "Day " << day + 1 << ": " << dayAverages[day] << "°C\n";
    }

    cout << "\nAverage Temperature for Each Hour:\n";
    for (int hour = 0; hour < HOURS; ++hour) {
        cout << "Hour " << hour << ": " << hourAverages[hour] << "°C\n";
    }

    cout << "\nAverage Temperature for the Week: " << weeklyAverage << "°C\n";
    cout << "Highest Temperature: " << maxTemp << "°C on Day " << maxDay + 1 << "\n";
    cout << "Lowest Temperature: " << minTemp << "°C on Day " << minDay + 1 << "\n";

    return 0;
}

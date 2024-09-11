/* A hospital is tracking patient records in a two-dimensional array. The rows represent different
patients, and the columns represent various health indicators (e.g., temperature, blood pressure, heart
rate).
Write a program to:
- Update the health indicators for a specific patient.
- Search for a patient with a critical health condition (e.g., heart rate > 120).
- Display the average value of each health indicator for all patients. */
#include <iostream>
using namespace std;

void updateIndicators(int healthRecords[][3], int patientIndex, int newIndicators[3])
{
    for (int i = 0; i < 3; i++)
    {
        healthRecords[patientIndex][i] = newIndicators[i];
    }
    cout << "\n\tPatient " << patientIndex + 1 << "'s health records updated.\n";
}

void searchCriticalCondition(int healthRecords[][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (healthRecords[i][2] > 120) 
        {
            cout << "Patient " << i + 1 << " has a critical heart rate: " << healthRecords[i][2] << endl;
        }
    }
}

void displayAverage(int healthRecords[][3])
{
    double average[3] = {0};

    for (int j = 0; j < 3; j++)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += healthRecords[i][j];
        }
        average[j] = static_cast<double>(sum) / 3;
    }

    cout << "\nAverage values for each health indicator:\n";
    for (int j = 0; j < 3; j++)
    {
        cout << "\n\tIndicator " << j + 1 << " average: " << average[j] << "\n";
    }
}

int main()
{
    

    int healthRecords[3][3] = {
        {98, 120, 110}, // Patient 1
        {99, 125, 130}, // Patient 2
        {97, 115, 100}  // Patient 3
    };

    int patientIndex;
    cout << "\n\tEnter the number of patient to update (1 to " << 3 << "): ";
    cin >> patientIndex;
    patientIndex--;

    if (patientIndex >= 0 && patientIndex < 3)
    {
        int newIndicators[3];
        cout << "Enter new health indicators for patient " << (patientIndex + 1) << ":\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "\n\tIndicator " << i + 1 << " : ";
            cin >> newIndicators[i];
        }
        updateIndicators(healthRecords, patientIndex, newIndicators);
    }
    else
    {
        cout << "\n\tInvalid patient number\n";
    }

    searchCriticalCondition(healthRecords);
    displayAverage(healthRecords);

    return 0;
}

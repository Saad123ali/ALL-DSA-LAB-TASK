/* In a coding competition, the scores of participants are stored in a one-dimensional array. Due to an
error, one score was added multiple times. Write a program to identify and remove duplicate scores
from the array, ensuring that each participant’s score is unique. */

#include <iostream>
using namespace std;

void removeDuplicates(int scores[], int &participants)
{
    int uniqueCount = 0;
    for (int i = 0; i < participants; i++)
    {
        bool isUnique = false;
        for(int j = 0; j <uniqueCount; j++)
        {
            if(scores[i] == scores[j])
            {
                isUnique = true;
            }
        }
        if(isUnique == false)
        {
            scores[uniqueCount++] = scores[i];
        } 
    }
    participants = uniqueCount;
}

int main()
{
    int participants = 5;
    int scores[participants];
    cout << "\n\tEnter the scores of Partcipants : ";
    for (int i = 0; i < participants; i++)
    {
        cin >> scores[i];
    }

    removeDuplicates(scores, participants);

    cout << "\n\tUnique score are : ";
    for (int i = 0; i < participants; i++)
    {
        cout << scores[i] << " ";
    }
}
/* You are developing a program for an online quiz application. The scores of each participant in 5
different subjects are stored in a two-dimensional array. Write a program that:
- Calculates the total score of each participant.
- Identifies the participant with the highest total score.
- Sorts the participants based on their scores in ascending order and displays the sorted results.  */

#include <iostream>
using namespace std;


int main()
{
int numParticipants = 5;
int numSubjects = 5;

int scores[numParticipants][numSubjects] = {
    {85, 90, 78, 92, 88},
    {75, 80, 85, 70, 90},
    {90, 88, 85, 91, 87},
    {60, 75, 70, 80, 65},
    {95, 93, 92, 90, 89}};
 
    int totalScore[numParticipants] = {0};

    for(int i = 0; i < numParticipants; i++)
    {
        int total = 0;
        for(int j = 0; j < numSubjects; j++)
        {
            total += scores[i][j];
        }
        totalScore[i] = total;
    }
    int maxPartcipant =  0;
    int maxScore = totalScore[0];;
    for(int i = 1; i < numParticipants; i++)
    {
       if(totalScore[i] > maxScore)
       {
            maxScore = totalScore[i];
            maxPartcipant = i;
       }
    }

    cout<<"\n\tPartcipant No : "<<maxPartcipant +1 << " with highest score : "<<maxScore<<"\n";

    for(int i=0; i<numParticipants; i++)
    {
        for(int j=0; j < numParticipants -i - 1; j++)
        {
            if(totalScore[j]  > totalScore[j+1])
            {
                int temp = totalScore[j];
                totalScore[j] = totalScore[j+1];
                totalScore[j+1] = temp;
            }
        }
    }    
    
    cout<<"\n\tEach Participant with total scores"<<"\n";
    for(int i = 0; i < numParticipants; i++)
    {
        int partcipantNo = 0;
        for(int j = 0; j < numParticipants; j++)
        {
            if(totalScore[i] == totalScore[j])
            {
                partcipantNo = j;
            }
        }
        cout<<"\n\tPartcipant No : "<<partcipantNo + 1<< " with the total score : "<<totalScore[i]<<"\n";
    }

    return 0;

}
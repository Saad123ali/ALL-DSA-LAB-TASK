/*  A sports league records the scores of teams for each game in a season. The league wants to track the 
top-performing teams. 
Write a program that uses an array to store the scores and then sorts the array 
to display the teams in descending order of their scores.   */

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b= temp;
}

void selectSortDescending(int scores[] ,int teams)
{
    for(int i = 0; i < teams - 1; i++)
    {
        int maxindex = i;
        for(int j = i+1; j <teams; j++)
        {
            if(scores[j] > scores[maxindex])
            {
                maxindex = j;
            }
        }
        swap(scores[i], scores[maxindex]);
    }
}

int main()
{
    int teams;
    cout<<"\n\tEnter the number of teams : ";
    cin >> teams;
    int scores[teams];
    
    cout<<"\n\tEnter the scores of each team : \n";
    for(int i=0; i<teams; i++)
    {
        cout<<"\n\tEnter the score of team : "<<i + 1<< " : ";
        cin>>scores[i];
    }

    selectSortDescending(scores , teams);

    cout<<"\n\tScores of each teams \n";
    for(int i=0; i<teams; i++)
    {
        cout<<"\n\tTeam : "<<i + 1<< " score : "<<scores[i]<<"\n";
    }
    return 0;
}
// TASK 2

#include <iostream>
using namespace std;
int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int search;
    cout << "Enter the Number to search in an Array" << endl;
    cin >> search;
    bool found = false;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == search)
        {
            cout << "Search Found at index : " << i << endl;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Search Failed" << endl;
    }
}
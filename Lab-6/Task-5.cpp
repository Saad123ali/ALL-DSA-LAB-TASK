#include <iostream>
#include <string>
using namespace std;

class SongNode
{
public:
    string songName;
    SongNode *prev;
    SongNode *next;

    // Constructor
    SongNode(string name)
    {
        songName = name;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist
{
private:
    SongNode *head;
    SongNode *tail;

public:
    // Constructor
    Playlist()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Add a new song to the end of the playlist
    void addSongToEnd(string songName)
    {
        SongNode *newSong = new SongNode(songName);
        if (!head)
        {
            head = tail = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Added song: " << songName << endl;
        printPlaylist();
    }

    // Traverse the playlist forwards
    void traverseForward()
    {
        cout << "Playlist (Forward): ";
        SongNode *temp = head;
        while (temp)
        {
            cout << temp->songName << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Traverse the playlist backwards
    void traverseBackward()
    {
        cout << "Playlist (Backward): ";
        SongNode *temp = tail;
        while (temp)
        {
            cout << temp->songName << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Delete a song from the playlist
    void deleteSong(string songName)
    {
        SongNode *temp = head;

        while (temp)
        {
            if (temp->songName == songName)
            {
                // Found the song to delete
                if (temp == head)
                {
                    head = temp->next; // Move head if needed
                    if (head)
                        head->prev = nullptr; // Update head's previous
                }
                else
                {
                    temp->prev->next = temp->next; // Link previous to next
                }

                if (temp == tail)
                {
                    tail = temp->prev; // Move tail if needed
                    if (tail)
                        tail->next = nullptr; // Update tail's next
                }
                else
                {
                    if (temp->next)
                        temp->next->prev = temp->prev; // Link next's previous
                }

                delete temp;
                cout << "Deleted song: " << songName << endl;
                printPlaylist();
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found: " << songName << endl;
    }

    // Print the current playlist
    void printPlaylist()
    {
        cout << "Current Playlist: ";
        SongNode *temp = head;
        while (temp)
        {
            cout << temp->songName << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Playlist()
    {
        while (head)
        {
            SongNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    Playlist myPlaylist;
    string songName, del;
    char c;

    while (true)
    {
        cout << "\nEnter the song name: ";
        getline(cin, songName);
        myPlaylist.addSongToEnd(songName);

        cout << "Do you want to add another song? (y/n): ";
        cin >> c;     
        cin.ignore(); 

        if (c == 'N' || c == 'n')
        {
            break; 
        }
    }

    // Traversing the playlist
    myPlaylist.traverseForward();
    myPlaylist.traverseBackward();

    cout << "Enter the song name do you want to delete : " << endl;
    getline(cin, del);
    myPlaylist.deleteSong(del);

    myPlaylist.traverseForward();

    return 0;
}

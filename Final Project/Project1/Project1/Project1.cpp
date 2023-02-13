#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int SIZE = 50;

struct Song {
   string artist;
   string title;
};

class Queue {
    string arr[SIZE];
    int rear;
    int front;
    

public:
    Queue() : front(-1), rear(-1) {}

    void enque(string value) {
        if (rear == SIZE - 1) {
            cout << "Queue overflow"<<endl;
        }
        arr[++rear] = value;
    }

    string deque() {
        if (front == rear) {
            return "Queue is Underflow";
        }
        return arr[++front];
    }

    bool empty() {
        return front == rear;
    }
};


void deleteSong(map<string, vector<Song>>& songs, const string& artist, const string& title) {
    auto it = songs.find(artist);
    if (it == songs.end()) return;

    auto& artistSongs = it->second;
    auto songIt = remove_if(artistSongs.begin(), artistSongs.end(), [&](const Song& song) {
        return song.title == title;
        });

    artistSongs.erase(songIt, artistSongs.end());

    if (artistSongs.empty()) {
        songs.erase(it);
    }
}
void display(map<string, vector<Song>>& songs ) {
    cout << "Here is the List Data" << endl;
    int i = 1;
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        const string& key = it->first;
        const vector<Song>& value = it->second;       
        for (const auto& song : value) {
            cout<<" " << i++ << ". Artist name: " + song.artist << ", Song Title: " + song.title << endl;
        }
    }
}
void addSong(map<string, vector<Song>>& songs) {
    string title;
    string artist;
    cout << "  Enter the artist name: ";
    getline(cin, artist);
    cout << "  Enter the song title: ";
    getline(cin, title);

    songs[artist].push_back({ artist,title });
    cout << "Song added successfully!" << endl;
}
void searchSong(map<string, vector<Song>>& songs) {
    string artist;
    cout << "  Enter the artist name: ";
    getline(cin,artist);
    if (songs.count(artist) == 0) {
        cout << "No songs found by the artist " << artist << endl;
    }
    else {
        vector<Song> artist_songs = songs[artist];
        cout << endl<<"Here is Songs list"<<endl;
        int i = 1;
        for (const auto& song : artist_songs) {
            cout<<"  " << i++ << ". " + song.title << endl;
        }
    }
}
void moveSongToQueue(map<string, vector<Song>>& songs,Queue& queue) {
    cout << "  Enter artist name: ";
    string artist;
    getline(cin, artist);
    cout << "  Enter song title: ";
    string title;
    getline(cin, title);

    bool check = false;

    auto it = songs.find(artist);
    if (it != songs.end()) {
        vector<Song>& songsList = it->second;
        for (auto it = songsList.begin(); it != songsList.end(); ++it) {
            if (it->title == title) {
                check = true;
                break;
            }
        }
        if (check == true) {
            deleteSong(songs, artist, title);
            queue.enque(title);
            cout << "\nSong moved to Queue\n" << endl;
        }
    }
    else {
        cout << "Song not found in the list" << endl;
    }
}
void deleteSong(map<string, vector<Song>>& songs) {
    cout << "  Enter artist name: ";
    string artist;
    getline(cin,artist);
    cout << "  Enter song title: ";
    string title;
    getline(cin,title);

    bool check = false;

    auto it = songs.find(artist);
    if (it != songs.end()) {
        vector<Song>& songsList = it->second;
        for (auto it = songsList.begin(); it != songsList.end(); ++it) {
            if (it->title == title) {
                check = true;
                break;
            }
        }
        if (check == true) {
            deleteSong(songs, artist, title);
            cout << endl;
        }
    }
    else {
        cout << "\nSong not found in the List\n" << endl;
    }
}

int main() {

    // Creating songs list
    map<string, vector<Song>> Songs;
    Songs["artist1"].push_back({ "artist1","song item"});
    Songs["artist1"].push_back({"artist1","hollywood song"});
    Songs["artist_gm"].push_back({ "artist_gm","new song"});
    Songs["artist_gm"].push_back({ "artist_gm","waka waka"});

    //Creating songs queue
    Queue queue;
    string choice = "";
    cout << "\n       Welcome to Songs Project        \n" << endl;
    while (choice!="7") {

        cout << "Please select any option(1-7)" << endl;
        cout << "  1. Search song by artist name" << endl;
        cout << "  2. Add song " << endl;
        cout << "  3. Display List of songs" << endl;
        cout << "  4. Move song to queue" << endl;
        cout << "  5. Display Songs Queue" << endl;
        cout << "  6. Remove song permanently" << endl;
        cout << "  7. Exit" << endl;

        cout << "  Enter choice: ";
        choice = "";

        getline(cin, choice);

        //if choice = 1
        if (choice == "1") {
            // Searching for songs by the artist name
            searchSong(Songs);
            cout << endl;
        }
        //choice =2
        else if (choice == "2") {
            // Adding a new song
            addSong(Songs);
            cout << endl;
        }
        //choice = 3
        else if (choice == "3") {
            //Display list of songs
            cout << endl;
            display(Songs);
            cout << endl;
        }
        // choice = 4
        else if (choice == "4") {
            //Move list song to queue
            moveSongToQueue(Songs, queue);
        }
        // choice = 5
        else if (choice == "5") {
            //queue.print();
            Queue q;
            cout << "\nList of songs in Queue" << endl;
            int i = 1;
            while (!queue.empty()) {
                string title = queue.deque();
                q.enque(title);
                cout << "  "<<i++<<". "+ title << endl;
            }
            queue = q;            
            cout << endl;
        }
        //choice = 6
        else if (choice == "6") {
            deleteSong(Songs);
            cout << "Song Deleted Successfully\n\n";
        }
        else {
            cout << "\nYou entered wrong option, Try again\n";
        }
    }
    cout<< "\nThank you!!!\n";

    return 0;
}

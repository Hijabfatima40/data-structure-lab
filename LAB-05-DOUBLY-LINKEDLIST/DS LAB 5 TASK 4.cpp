#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string songName;
    Node* next;

    Node(string name) {
        songName = name;
        next = NULL;
    }
};

class MusicPlaylist {
public:
    Node* head;

    MusicPlaylist() {
        head = NULL;
    }

    void addSong(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    void displaySongs() {
        Node* temp = head;

        cout << "Playlist:" << endl;

        do {
            cout << temp->songName << endl;
            temp = temp->next;
        } while (temp != head);
    }
    void playTwoRounds() {
        Node* temp = head;

        cout << "\nPlaying Playlist for 2 Rounds:" << endl;

        for (int i = 1; i <= 10; i++) {
            cout << "Playing: " << temp->songName << endl;
            temp = temp->next;
        }
    }
};

int main() {

    MusicPlaylist playlist;

    playlist.addSong("A Thousand Years");
    playlist.addSong("Perfect");
    playlist.addSong("Believer");
    playlist.addSong("Faded");
    playlist.addSong("Counting Stars");

    playlist.displaySongs();
    playlist.playTwoRounds();

    return 0;
}

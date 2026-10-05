#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string playerName;
    Node* next;

    Node(string name) {
        playerName = name;
        next = NULL;
    }
};
class GamePlayers {
public:
    Node* head;

    GamePlayers() {
        head = NULL;
    }

    void addPlayer(string name) {
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
    void displayTurns() {
        if (head == NULL) {
            cout << "No players available." << endl;
            return;
        }

        Node* temp = head;

        cout << "Player Turns:" << endl;

        do {
            cout << temp->playerName << "'s turn" << endl;
            temp = temp->next;
        } while (temp != head);
    }
    void showNextTurn() {
        Node* temp = head;
        for (int i = 1; i <= 5; i++) {
            cout << temp->playerName << " -> ";
            temp = temp->next;
        }

        cout << temp->playerName << endl;
    }
};

int main() {

    GamePlayers game;

    game.addPlayer("Ali");
    game.addPlayer("Umair");
    game.addPlayer("Bilal");
    game.addPlayer("Riyan");
    game.addPlayer("Hamza");

    game.displayTurns();

    cout << "\nAfter the last player, turn returns to:" << endl;
    game.showNextTurn();

    return 0;
}


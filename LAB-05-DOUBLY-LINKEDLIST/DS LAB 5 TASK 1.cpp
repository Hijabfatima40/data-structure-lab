#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    Node* head;
    Node* tail;

    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    void addWebsite(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* temp = head;

        cout << "First Visited -> Last Visited:" << endl;

        while (temp != NULL) {
            cout << temp->website << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Node* temp = tail;

        cout << "\nLast Visited -> First Visited:" << endl;

        while (temp != NULL) {
            cout << temp->website << endl;
            temp = temp->prev;
        }
    }
};

int main() {

    BrowserHistory history;

    history.addWebsite("Google");
    history.addWebsite("YouTube");
    history.addWebsite("Facebook");
    history.addWebsite("GitHub");
    history.addWebsite("Wikipedia");

    history.displayForward();
    history.displayBackward();

    return 0;
}


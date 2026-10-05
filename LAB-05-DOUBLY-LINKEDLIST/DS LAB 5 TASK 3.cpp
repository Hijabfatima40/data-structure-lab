#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string imageName;
    Node* prev;
    Node* next;

    Node(string name) {
        imageName = name;
        prev = NULL;
        next = NULL;
    }
};
class ImageGallery {
public:
    Node* head;
    Node* tail;

    ImageGallery() {
        head = NULL;
        tail = NULL;
    }
    void addImage(string name) {
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

        cout << "Images (First -> Last):" << endl;

        while (temp != NULL) {
            cout << temp->imageName << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Node* temp = tail;

        cout << "\nImages (Last -> First):" << endl;

        while (temp != NULL) {
            cout << temp->imageName << endl;
            temp = temp->prev;
        }
    }
};

int main() {

    ImageGallery gallery;

    gallery.addImage("Nature.jpg");
    gallery.addImage("Family.jpg");
    gallery.addImage("Friends.jpg");
    gallery.addImage("Beach.jpg");
    gallery.addImage("Mountain.jpg");

    gallery.displayForward();
    gallery.displayBackward();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "No patient requests!" << endl;
            return;
        }

        Node* temp = top;
        cout << "\nHandled patient request: "
             << temp->patientID << endl;

        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "No requests remaining." << endl;
            return;
        }

        cout << "\nPatient Requests (TOP to Bottom):" << endl;

        Node* temp = top;

        while (temp != NULL) {
            cout << temp->patientID << endl;
            temp = temp->next;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "\nNo current TOP request." << endl;
        } else {
            cout << "\nCurrent TOP request: "
                 << top->patientID << endl;
        }
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack hospital;

    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    hospital.display();

    hospital.pop();

    hospital.displayTop();

    hospital.display();

    return 0;
}

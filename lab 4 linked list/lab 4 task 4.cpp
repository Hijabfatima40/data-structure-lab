#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* next;
};

void addStudent(Node*& head, int roll) {
    Node* newNode = new Node;
    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertBeginning(Node*& head, int roll) {
    Node* newNode = new Node;
    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
}

void searchStudent(Node* head, int roll) {
    while (head != NULL) {
        if (head->roll == roll) {
            cout << "Student Found" << endl;
            return;
        }

        head = head->next;
    }

    cout << "Student Not Found" << endl;
}

void display(Node* head) {
    cout << "Enrolled Students: ";

    while (head != NULL) {
        cout << head->roll;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = NULL;
    int roll;

    addStudent(head, 22);
    addStudent(head, 35);
    addStudent(head, 41);
    addStudent(head, 56);

    cout << "Initially:" << endl;
    display(head);

    cout << "Enter Roll Number to Insert at Beginning: ";
    cin >> roll;

    insertBeginning(head, roll);

    cout << "After Insertion:" << endl;
    display(head);

    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    searchStudent(head, roll);

    return 0;
}


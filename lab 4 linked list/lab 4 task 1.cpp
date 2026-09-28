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

void display(Node* head) {
    cout << "Registered Students: ";

    while (head != NULL) {
        cout << head->roll << " ";
        head = head->next;
    }

    cout << endl;
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

int main() {
    Node* head = NULL;
    int n, roll;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Roll Number: ";
        cin >> roll;
        addStudent(head, roll);
    }

    display(head);

    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    searchStudent(head, roll);

    return 0;
}



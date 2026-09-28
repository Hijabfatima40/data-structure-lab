#include <iostream>
using namespace std;

struct Node {
    int productID;
    Node* next;
};

void addProduct(Node*& head, int id) {
    Node* newNode = new Node;
    newNode->productID = id;
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
    cout << "Shopping Cart: ";

    while (head != NULL) {
        cout << "P" << head->productID << " ";
        head = head->next;
    }

    cout << endl;
}

void removeProduct(Node*& head, int id) {
    if (head == NULL)
        return;

    if (head->productID == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        if (temp->next->productID == id) {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            return;
        }

        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int n, id;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Product ID: ";
        cin >> id;
        addProduct(head, id);
    }

    display(head);

    cout << "Enter Product ID to Remove: ";
    cin >> id;

    removeProduct(head, id);

    cout << "Updated Cart: ";
    display(head);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
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
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Processed order: "
             << temp->orderID << endl;

        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "No orders remaining." << endl;
            return;
        }

        cout << "\nOrders (TOP to Bottom):" << endl;

        Node* temp = top;
        while (temp != NULL) {
            cout << temp->orderID << endl;
            temp = temp->next;
        }
    }
    void displayTop() {
        if (top == NULL) {
            cout << "\nNo TOP order available." << endl;
        } else {
            cout << "\nCurrent TOP order: "
                 << top->orderID << endl;
        }
    }
    bool isEmpty() {
        return top == NULL;
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
    Stack restaurant;
    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");
    
    restaurant.display();
    cout << "\nProcessing two orders:" << endl;
    restaurant.pop();
    restaurant.pop();

    restaurant.displayTop();
    restaurant.display();

    if (restaurant.isEmpty()) {
        cout << "\nStack is empty." << endl;
    } else {
        cout << "\nStack is not empty." << endl;
    }

    return 0;
}

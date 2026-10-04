
#include <iostream>
#include <string>
using namespace std;

struct Order {
    string orderId;
    string customer;
    string food;
    Order* next;
};
Order* head = NULL;

Order* createNode(const string& id, const string& cust, const string& food) {
    Order* n = new Order;
    n->orderId = id; n->customer = cust; n->food = food; n->next = NULL;
    return n;
}
void addOrderAtEnd(const string& id, const string& cust, const string& food) {
    Order* n = createNode(id, cust, food);
    if (!head) head = n;
    else {
        Order* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    cout << "Order " << id << " received.\n";
}
void addUrgentOrder(const string& id, const string& cust, const string& food) {
    Order* n = createNode(id, cust, food);
    n->next = head;
    head = n;
    cout << "Urgent Order " << id << " received.\n";
}
void displayChain() {
    if (!head) { cout << "(no pending orders)\n"; return; }
    for (Order* t = head; t; t = t->next) {
        cout << t->orderId;
        if (t->next) cout << " -> ";
    }
    cout << "\n";
}
void displayOrders() {
    cout << "\nPending Orders:\n";
    displayChain();
    if (head) {
        cout << "\nDetails:\n";
        for (Order* t = head; t; t = t->next)
            cout << "  " << t->orderId << " | Customer: " << t->customer << " | Item: " << t->food << "\n";
    }
}
void searchOrder(const string& id) {
    for (Order* t = head; t; t = t->next) {
        if (t->orderId == id) {
            cout << "Order found -> ID: " << t->orderId << ", Customer: " << t->customer
                 << ", Item: " << t->food << "\n";
            return;
        }
    }
    cout << "Order " << id << " not found.\n";
}
void removeOrder(const string& id) {
    Order* t = head; Order* prev = NULL;
    while (t && t->orderId != id) { prev = t; t = t->next; }
    if (!t) { cout << "Order " << id << " not found.\n"; return; }
    if (!prev) head = t->next; else prev->next = t->next;
    cout << "Order " << id << " delivered.\n";
    delete t;
}
void freeList() {
    while (head) { Order* t = head; head = head->next; delete t; }
}
int main() {
    
    cout << "DEMO (as per task example) =\n";
    addOrderAtEnd("O101", "Ali", "Burger");
    addOrderAtEnd("O102", "Sara", "Pizza");
    addOrderAtEnd("O103", "Ahmed", "Biryani");
    cout << "\nPending Orders:\n"; displayChain();
    addUrgentOrder("O104", "Huzaifa", "Zinger Wrap");
    displayChain();
    removeOrder("O101");
    displayChain();
    int choice; string id, cust, food;
    do {
        cout << "\n===== Online Food Delivery Orders =====\n"
             << "1. Add new order at the end\n"
             << "2. Display all pending orders\n"
             << "3. Search order by Order ID\n"
             << "4. Remove order (delivered)\n"
             << "5. Add urgent order at the beginning\n"
             << "6. Display updated pending-order list\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: case 5:
                cout << "Enter Order ID: "; cin >> id;
                cout << "Enter Customer Name: "; cin.ignore(); getline(cin, cust);
                cout << "Enter Food Item: "; getline(cin, food);
                if (choice == 1) addOrderAtEnd(id, cust, food);
                else addUrgentOrder(id, cust, food);
                break;
            case 2: case 6: displayOrders(); break;
            case 3: cout << "Enter Order ID: "; cin >> id; searchOrder(id); break;
            case 4: cout << "Enter Order ID: "; cin >> id; removeOrder(id); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    freeList();
    return 0;
}

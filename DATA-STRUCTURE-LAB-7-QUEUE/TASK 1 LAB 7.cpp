#include <iostream>
using namespace std;

#define SIZE 5
class BankQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    BankQueue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! No more space available.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = token;

        cout << "Customer " << token
             << " added to the queue.\n";
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No customers waiting.\n";
            return;
        }

        cout << "Serving customer: "
             << queue[front] << endl;

        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }
    void display() {
        if (front == -1) {
            cout << "No customers waiting.\n";
            return;
        }
        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
    void countCustomers() {
        if (front == -1) {
            cout << "Number of waiting customers: 0\n";
        } else {
            cout << "Number of waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main() {
    BankQueue bank;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service System ---\n";
        cout << "1. Add Customer (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Count Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer token number: ";
                cin >> token;
                bank.enqueue(token);
                break;

            case 2:
                bank.dequeue();
                break;

            case 3:
                bank.display();
                break;

            case 4:
                bank.countCustomers();
                break;

            case 5:
                cout << "Exiting Bank Service System.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
    return 0;
}

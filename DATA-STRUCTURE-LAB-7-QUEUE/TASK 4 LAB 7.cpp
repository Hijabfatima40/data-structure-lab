#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
private:
    int requests[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }
    
    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque is full! Cannot insert request.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        requests[front] = id;
        count++;

        cout << "Request " << id << " inserted at front.\n";
    }
    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque is full! Cannot insert request.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        requests[rear] = id;
        count++;

        cout << "Request " << id << " inserted at rear.\n";
    }
    void removeFront() {
        if (count == 0) {
            cout << "Deque is empty! Nothing to remove.\n";
            return;
        }

        cout << "Request " << requests[front]
             << " removed from front.\n";

        if (count == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        count--;
    }
    void removeRear() {
        if (count == 0) {
            cout << "Deque is empty! Nothing to remove.\n";
            return;
        }

        cout << "Request " << requests[rear]
             << " removed from rear.\n";

        if (count == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }

        count--;
    }
    void display() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Front -> ";

        for (int i = 0; i < count; i++) {
            cout << requests[(front + i) % SIZE];

            if (i < count - 1) {
                cout << ", ";
            }
        }

        cout << " <- Rear\n";
    }
};

int main() {
    Deque dq;
    int choice, id;

    do {
        cout << "\n--- Train Station Request Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter request ID: ";
                cin >> id;
                dq.insertFront(id);
                break;

            case 2:
                cout << "Enter request ID: ";
                cin >> id;
                dq.insertRear(id);
                break;

            case 3:
                dq.removeFront();
                break;

            case 4:
                dq.removeRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

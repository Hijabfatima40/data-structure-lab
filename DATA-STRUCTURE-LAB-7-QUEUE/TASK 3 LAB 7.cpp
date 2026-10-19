#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;

struct Patient {
    string id;
    int priority;
};

class PriorityQueue {
private:
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }
    void insertPatient(string id, int priority) {
        if (count == SIZE) {
            cout << "Queue is full!\n";
            return;
        }

        patients[count].id = id;
        patients[count].priority = priority;
        count++;

        cout << "Patient added successfully.\n";
    }
    void treatPatient() {
        if (count == 0) {
            cout << "Queue is empty! No patient to treat.\n";
            return;
        }

        int highest = 0;
        for (int i = 1; i < count; i++) {
            if (patients[i].priority < patients[highest].priority) {
                highest = i;
            }
        }

        cout << "Treating Patient: " << patients[highest].id
             << ", Priority: " << patients[highest].priority
             << endl;
        for (int i = highest; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }

        count--;
    }
    void displayPatients() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "\nPatient ID\tPriority\n";

        for (int i = 0; i < count; i++) {
            cout << patients[i].id << "\t\t"
                 << patients[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, priority;
    string id;

    do {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;

                cout << "Enter Priority (1 = Highest): ";
                cin >> priority;

                if (priority < 1) {
                    cout << "Invalid priority!\n";
                } else {
                    pq.insertPatient(id, priority);
                }
                break;

            case 2:
                pq.treatPatient();
                break;

            case 3:
                pq.displayPatients();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

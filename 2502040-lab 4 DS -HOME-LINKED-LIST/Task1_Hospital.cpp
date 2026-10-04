
#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    Patient* next;
};

Patient* head = NULL;

Patient* createNode(int id, const string& name, int age) {
    Patient* n = new Patient;
    n->id = id; n->name = name; n->age = age; n->next = NULL;
    return n;
}

void addAtEnd(int id, const string& name, int age) {
    Patient* n = createNode(id, name, age);
    if (!head) { head = n; }
    else {
        Patient* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    cout << "Patient " << name << " added at the end of the waiting list.\n";
}

void addAtBeginning(int id, const string& name, int age) {
    Patient* n = createNode(id, name, age);
    n->next = head;
    head = n;
    cout << "EMERGENCY patient " << name << " added at the beginning.\n";
}

void searchPatient(int id) {
    Patient* t = head;
    int pos = 1;
    while (t) {
        if (t->id == id) {
            cout << "Patient found at position " << pos << " -> ID: " << t->id
                 << ", Name: " << t->name << ", Age: " << t->age << "\n";
            return;
        }
        t = t->next; pos++;
    }
    cout << "Patient with ID " << id << " does not exist.\n";
}

void removePatient(int id) {
    if (!head) { cout << "Waiting list is empty. No patient to remove.\n"; return; }
    Patient* t = head; Patient* prev = NULL;
    while (t && t->id != id) { prev = t; t = t->next; }
    if (!t) { cout << "Patient with ID " << id << " does not exist.\n"; return; }
    if (!prev) head = t->next; else prev->next = t->next;
    cout << "Patient " << t->name << " (ID " << id << ") treated and removed from the list.\n";
    delete t;
}

void displayPatients() {
    if (!head) { cout << "No patients in the waiting list.\n"; return; }
    cout << "\n--- Waiting Patients ---\n";
    Patient* t = head; int i = 1;
    while (t) {
        cout << i++ << ". ID: " << t->id << " | Name: " << t->name << " | Age: " << t->age << "\n";
        t = t->next;
    }
}

void freeList() {
    while (head) { Patient* t = head; head = head->next; delete t; }
}

int main() {
    int choice, id, age; string name;
    do {
        cout << "\n= Hospital Emergency Patient Management =\n"
             << "1. Add new patient at the end\n"
             << "2. Add emergency patient at the beginning\n"
             << "3. Search patient by ID\n"
             << "4. Remove patient after treatment\n"
             << "5. Display all waiting patients\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: case 2:
                cout << "Enter Patient ID: "; cin >> id;
                cout << "Enter Patient Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Patient Age: "; cin >> age;
                if (choice == 1) addAtEnd(id, name, age);
                else addAtBeginning(id, name, age);
                break;
            case 3: cout << "Enter Patient ID to search: "; cin >> id; searchPatient(id); break;
            case 4: cout << "Enter Patient ID to remove: "; cin >> id; removePatient(id); break;
            case 5: displayPatients(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    freeList();
    return 0;
}

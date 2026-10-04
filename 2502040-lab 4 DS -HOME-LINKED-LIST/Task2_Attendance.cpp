
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    char status;      
    Student* next;
};
Student* head = NULL;
void addStudent(int roll, const string& name, char status) {
    Student* n = new Student;
    n->roll = roll; n->name = name; n->status = status; n->next = NULL;
    if (!head) head = n;
    else {
        Student* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    cout << "Student " << name << " added to the attendance list.\n";
}
void searchStudent(int roll) {
    for (Student* t = head; t; t = t->next) {
        if (t->roll == roll) {
            cout << "Found -> Roll No: " << t->roll << ", Name: " << t->name
                 << ", Status: " << (t->status == 'P' ? "Present" : "Absent") << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
void deleteStudent(int roll) {
    Student* t = head; Student* prev = NULL;
    while (t && t->roll != roll) { prev = t; t = t->next; }
    if (!t) { cout << "Student not found.\n"; return; }
    if (!prev) head = t->next; else prev->next = t->next;
    cout << "Student " << t->name << " deleted from the list.\n";
    delete t;
}
void displayStudents() {
    if (!head) { cout << "Attendance list is empty.\n"; return; }
    cout << "\nRoll No\tName\t\tStatus\n";
    for (Student* t = head; t; t = t->next)
        cout << t->roll << "\t" << t->name << "\t\t" << (t->status == 'P' ? "Present" : "Absent") << "\n";
}
int countPresent() {
    int c = 0;
    for (Student* t = head; t; t = t->next) if (t->status == 'P') c++;
    return c;
}
void displayFinalAttendance() {
    cout << "\n===== FINAL ATTENDANCE LIST =====";
    displayStudents();
    cout << "Total students present: " << countPresent() << "\n";
}
void freeList() {
    while (head) { Student* t = head; head = head->next; delete t; }
}
int main() {
    int choice, roll; string name; char status;
    do {
        cout <<"\n University Attendance System \n"
             <<"1. Add a student\n"
             <<"2. Search student by Roll Number\n"
             <<"3. Delete a student\n"
             <<"4. Display all students\n"
             <<"5. Count students present\n"
             <<"6. Display final attendance list\n"
             <<"0. Exit\n"
             <<"Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout <<"Enter Roll Number: "; cin >> roll;
                cout <<"Enter Student Name: "; cin.ignore(); getline(cin, name);
                cout <<"Enter Attendance Status (P = Present, A = Absent): "; cin >> status;
                status=(status == 'p' || status == 'P') ? 'P' : 'A';
                addStudent(roll, name, status);
                break;
            case 2: cout << "Enter Roll Number: "; cin >> roll; searchStudent(roll); break;
            case 3: cout << "Enter Roll Number: "; cin >> roll; deleteStudent(roll); break;
            case 4: displayStudents(); break;
            case 5: cout << "Total students present: " << countPresent() << "\n"; break;
            case 6: displayFinalAttendance(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    freeList();
    return 0;
}

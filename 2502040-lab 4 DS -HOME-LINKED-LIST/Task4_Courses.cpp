
#include <iostream>
#include <string>
using namespace std;

struct Course {
    string code;
    string name;
    int credits;
    Course* next;
};
Course* createNode(const string& code, const string& name, int cr) {
    Course* n = new Course;
    n->code = code; n->name = name; n->credits = cr; n->next = NULL;
    return n;
}
void addAtBeginning(Course*& head, const string& code, const string& name, int cr) {
    Course* n = createNode(code, name, cr);
    n->next = head;
    head = n;
    cout << "Course " << code << " added at the beginning.\n";
}
void addAtEnd(Course*& head, const string& code, const string& name, int cr) {
    Course* n = createNode(code, name, cr);
    if (!head) head = n;
    else {
        Course* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    cout << "Course " << code << " added at the end.\n";
}
void searchCourse(Course* head, const string& code) {
    for (Course* t = head; t; t = t->next) {
        if (t->code == code) {
            cout << "Course found -> Code: " << t->code << ", Name: " << t->name
                 << ", Credit Hours: " << t->credits << "\n";
            return;
        }
    }
    cout << "Course " << code << " not found.\n";
}
void deleteCourse(Course*& head, const string& code) {
    Course* t = head; Course* prev = NULL;
    while (t && t->code != code) { prev = t; t = t->next; }
    if (!t) { cout << "Course " << code << " not found.\n"; return; }
    if (!prev) head = t->next; else prev->next = t->next;
    cout << "Course " << code << " deleted.\n";
    delete t;
}
void displayCourses(Course* head, const string& title) {
    cout << "\n" << title << ":\n";
    if (!head) { cout << "(no courses)\n"; return; }
    for (Course* t = head; t; t = t->next) {
        cout << t->code;
        if (t->next) cout << " -> ";
    }
    cout << "\n";
    for (Course* t = head; t; t = t->next)
        cout << "  " << t->code << " | " << t->name << " | " << t->credits << " CH\n";
}
int countCourses(Course* head) {
    int c = 0;
    for (Course* t = head; t; t = t->next) c++;
    return c;
}
void concatenate(Course*& head, Course* other) {
    if (!other) { cout << "The other list is empty. Nothing to concatenate.\n"; return; }
    Course* tail = head;
    while (tail && tail->next) tail = tail->next;
    for (Course* t = other; t; t = t->next) {
        Course* n = createNode(t->code, t->name, t->credits);
        if (!head) { head = n; tail = n; }
        else { tail->next = n; tail = n; }
    }
    cout << "Lists concatenated successfully.\n";
}
void freeList(Course*& head) {
    while (head) { Course* t = head; head = head->next; delete t; }
}
int main() {
    Course* lists[2] = { NULL, NULL };
    const string titles[2] = { "Morning Courses", "Evening Courses" };
    int which, choice, cr; string code, name;
    do {
        cout << "\nWhich list do you want to work on?\n1. Morning Courses\n2. Evening Courses\n0. Exit\nEnter: ";
        cin >> which;
        if (which == 0) break;
        if (which != 1 && which != 2) { cout << "Invalid list.\n"; continue; }
        int i = which - 1;
        do {
            cout << "\n Course Management [" << titles[i] << "] \n"
                 << "1. Add Course at Beginning\n"
                 << "2. Add Course at End\n"
                 << "3. Search Course\n"
                 << "4. Delete Course\n"
                 << "5. Display All Courses\n"
                 << "6. Count Total Courses\n"
                 << "7. Concatenate Another Course List\n"
                 << "8. Exit (back to list selection)\n"
                 << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1: case 2:
                    cout << "Enter Course Code: "; cin >> code;
                    cout << "Enter Course Name: "; cin.ignore(); getline(cin, name);
                    cout << "Enter Credit Hours: "; cin >> cr;
                    if (choice == 1) addAtBeginning(lists[i], code, name, cr);
                    else addAtEnd(lists[i], code, name, cr);
                    break;
                case 3: cout << "Enter Course Code: "; cin >> code; searchCourse(lists[i], code); break;
                case 4: cout << "Enter Course Code: "; cin >> code; deleteCourse(lists[i], code); break;
                case 5: displayCourses(lists[i], titles[i]); break;
                case 6: cout << "Total number of courses: " << countCourses(lists[i]) << "\n"; break;
                case 7:
                    concatenate(lists[i], lists[1 - i]);
                    displayCourses(lists[i], "Combined Course List");
                    cout << "Total number of courses: " << countCourses(lists[i]) << "\n";
                    break;
                case 8: break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 8);
    } while (true);
    cout << "Exiting program...\n";
    freeList(lists[0]); freeList(lists[1]);
    return 0;
}

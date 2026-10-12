#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }
    void push(string action) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
        } else {
            actions[++top] = action;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "No actions to undo!" << endl;
        } else {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }
    void display() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
            return;
        }

        cout << "\nActions (TOP to Bottom):" << endl;

        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }
    void displayTop() {
        if (top == -1) {
            cout << "\nNo current TOP action." << endl;
        } else {
            cout << "\nCurrent TOP action: "
                 << actions[top] << endl;
        }
    }
};

int main() {
    Stack editor;
    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    editor.display();
    cout << "\nPerforming two Undo operations:" << endl;
    editor.pop();
    editor.pop();

    editor.displayTop();
    editor.display();

    return 0;
}

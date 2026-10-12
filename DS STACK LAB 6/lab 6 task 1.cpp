#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }
    void push(string page) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
        } else {
            pages[++top] = page;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "No browsing history!" << endl;
        } else {
            cout << "\nBack button pressed. Removed page: "
                 << pages[top] << endl;
            top--;
        }
    }
    void display() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
            return;
        }

        cout << "\nBrowsing History (TOP to Bottom):" << endl;

        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }
    void displayTop() {
        if (top == -1) {
            cout << "\nNo current page." << endl;
        } else {
            cout << "\nCurrent TOP page: " << pages[top] << endl;
        }
    }
};
int main() {
    Stack browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    browser.display();
    browser.pop();
    browser.displayTop();
    browser.display();

    return 0;
}

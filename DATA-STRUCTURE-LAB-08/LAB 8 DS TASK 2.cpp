
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int rollNumber;
        Node* left;
        Node* right;

        Node(int value) {
            rollNumber = value;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->rollNumber) {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->rollNumber) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrder(node->left);
        cout << node->rollNumber << " ";
        inOrder(node->right);
    }

public:

    BST() {
        root = NULL;
    }


    void insert(int value) {
        root = insertNode(root, value);
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST students;

    students.insert(45);
    students.insert(25);
    students.insert(65);
    students.insert(15);
    students.insert(35);
    students.insert(55);
    students.insert(75);

    int num1, num2;

    cout << "Enter first additional roll number: ";
    cin >> num1;

    cout << "Enter second additional roll number: ";
    cin >> num2;

    students.insert(num1);
    students.insert(num2);

    cout << "\nRoll numbers in ascending order:\n";
    students.display();

    return 0;
}


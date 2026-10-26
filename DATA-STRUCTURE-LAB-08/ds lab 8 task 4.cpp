
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int employeeID;
        Node* left;
        Node* right;

        Node(int id) {
            employeeID = id;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    Node* insertNode(Node* node, int id) {
        if (node == NULL) {
            return new Node(id);
        }

        if (id < node->employeeID) {
            node->left = insertNode(node->left, id);
        }
        else if (id > node->employeeID) {
            node->right = insertNode(node->right, id);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == NULL) {
            return NULL;
        }

        if (id < node->employeeID) {
            node->left = deleteNode(node->left, id);
        }
        else if (id > node->employeeID) {
            node->right = deleteNode(node->right, id);
        }
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->employeeID = temp->employeeID;
            node->right = deleteNode(node->right, temp->employeeID);
        }

        return node;
    }

    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrder(node->left);
        cout << node->employeeID << " ";
        inOrder(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int id) {
        root = insertNode(root, id);
    }

    void deleteEmployee(int id) {
        root = deleteNode(root, id);
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST employees;

    employees.insert(50);
    employees.insert(30);
    employees.insert(70);
    employees.insert(20);
    employees.insert(40);
    employees.insert(60);
    employees.insert(80);

    int id;

    cout << "Employee IDs before deletion: ";
    employees.display();

    cout << "Enter Employee ID to delete: ";
    cin >> id;

    employees.deleteEmployee(id);

    cout << "Employee IDs after deletion: ";
    employees.display();

    return 0;
}


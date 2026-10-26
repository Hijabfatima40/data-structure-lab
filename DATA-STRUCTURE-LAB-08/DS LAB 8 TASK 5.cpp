
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int patientID;
        Node* left;
        Node* right;

        Node(int id) {
            patientID = id;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    Node* insertNode(Node* node, int id) {
        if (node == NULL) {
            return new Node(id);
        }

        if (id < node->patientID) {
            node->left = insertNode(node->left, id);
        }
        else if (id > node->patientID) {
            node->right = insertNode(node->right, id);
        }

        return node;
    }

    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrder(node->left);
        cout << node->patientID << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->patientID << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << node->patientID << " ";
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int id) {
        root = insertNode(root, id);
    }

    void displayInOrder() {
        inOrder(root);
        cout << endl;
    }

    void displayPreOrder() {
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BST hospital;

    hospital.insert(40);
    hospital.insert(20);
    hospital.insert(60);
    hospital.insert(10);
    hospital.insert(30);
    hospital.insert(50);
    hospital.insert(70);

    cout << "In-order Traversal: ";
    hospital.displayInOrder();

    cout << "Pre-order Traversal: ";
    hospital.displayPreOrder();

    cout << "Post-order Traversal: ";
    hospital.displayPostOrder();

    cout << "Ascending Order: In-order Traversal" << endl;

    return 0;
}


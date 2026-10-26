
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int productID;
        Node* left;
        Node* right;

        Node(int id) {
            productID = id;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    Node* insertNode(Node* node, int id) {
        if (node == NULL) {
            return new Node(id);
        }

        if (id < node->productID) {
            node->left = insertNode(node->left, id);
        }
        else if (id > node->productID) {
            node->right = insertNode(node->right, id);
        }
        else {
            cout << "Duplicate product ID! Insertion not allowed.\n";
        }

        return node;
    }

    bool searchNode(Node* node, int id) {
        if (node == NULL) {
            return false;
        }

        if (node->productID == id) {
            return true;
        }

        if (id < node->productID) {
            return searchNode(node->left, id);
        }

        return searchNode(node->right, id);
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

        if (id < node->productID) {
            node->left = deleteNode(node->left, id);
        }
        else if (id > node->productID) {
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
            node->productID = temp->productID;
            node->right = deleteNode(node->right, temp->productID);
        }

        return node;
    }

    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrder(node->left);
        cout << node->productID << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->productID << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << node->productID << " ";
    }

    void destroyTree(Node* node) {
        if (node == NULL) {
            return;
        }

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroyTree(root);
    }

    void insert(int id) {
        root = insertNode(root, id);
    }

    void search(int id) {
        if (searchNode(root, id)) {
            cout << "Product found: " << id << endl;
        }
        else {
            cout << "Product not found: " << id << endl;
        }
    }

    void remove(int id) {
        if (!searchNode(root, id)) {
            cout << "Product not found. Cannot delete.\n";
            return;
        }

        root = deleteNode(root, id);
        cout << "Product deleted successfully.\n";
    }

    void displayInOrder() {
        if (root == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }

    void displayPreOrder() {
        if (root == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        if (root == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "Post-order Traversal: ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BST inventory;
    int choice, id;

    do {
        cout << "\n===== Online Store Inventory =====\n";
        cout << "1. Insert a product ID\n";
        cout << "2. Search for a product ID\n";
        cout << "3. Delete a product ID\n";
        cout << "4. Display in-order traversal\n";
        cout << "5. Display pre-order traversal\n";
        cout << "6. Display post-order traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID to insert: ";
            cin >> id;
            inventory.insert(id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            inventory.search(id);
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            inventory.remove(id);
            break;

        case 4:
            inventory.displayInOrder();
            break;

        case 5:
            inventory.displayPreOrder();
            break;

        case 6:
            inventory.displayPostOrder();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}


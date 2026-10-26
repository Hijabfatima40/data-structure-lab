
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int bookID;
        Node* left;
        Node* right;

        Node(int id) {
            bookID = id;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    Node* insertNode(Node* node, int id) {
        if (node == NULL) {
            return new Node(id);
        }

        if (id < node->bookID) {
            node->left = insertNode(node->left, id);
        }
        else if (id > node->bookID) {
            node->right = insertNode(node->right, id);
        }

        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int id) {
        root = insertNode(root, id);
    }

    void search(int id) {
        Node* current = root;
        int comparisons = 0;

        while (current != NULL) {
            comparisons++;

            if (current->bookID == id) {
                cout << "Book Found" << endl;
                cout << "Number of comparisons: "
                     << comparisons << endl;
                return;
            }
            else if (id < current->bookID) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        cout << "Book Not Found" << endl;
        cout << "Number of comparisons: "
             << comparisons << endl;
    }
};

int main() {
    BST library;

    library.insert(40);
    library.insert(20);
    library.insert(60);
    library.insert(10);
    library.insert(30);
    library.insert(50);
    library.insert(70);

    int id;

    cout << "Enter Book ID to search: ";
    cin >> id;

    library.search(id);

    return 0;
}


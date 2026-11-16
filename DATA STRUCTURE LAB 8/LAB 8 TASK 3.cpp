#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;
    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};
void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->folder << " ";
    inOrder(root->right);
}
void preOrder(Node* root) {
    if (root == NULL)
        return;

    cout << root->folder << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->folder << " ";
}

int main() {
    Node* root = new Node("Computer");

    Node* documents = new Node("Documents");
    Node* downloads = new Node("Downloads");
    Node* pictures = new Node("Pictures");
    Node* videos = new Node("Videos");
    Node* music = new Node("Music");
    Node* projects = new Node("Projects");

    root->left = documents;
    root->right = downloads;

    documents->left = pictures;
    documents->right = videos;

    downloads->left = music;
    downloads->right = projects;

    cout << "In-order Traversal:" << endl;
    inOrder(root);

    cout << "\n\nPre-order Traversal:" << endl;
    preOrder(root);

    cout << "\n\nPost-order Traversal:" << endl;
    postOrder(root);

    cout << endl;

    return 0;
}

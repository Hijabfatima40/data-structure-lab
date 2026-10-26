#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string personName) {
        name = personName;
        left = NULL;
        right = NULL;
    }
};

void displayTree(Node* root) {
    if (root == NULL)
        return;

    cout << "Person: " << root->name << endl;

    cout << "Left Child: ";
    if (root->left != NULL)
        cout << root->left->name;
    else
        cout << "None";

    cout << endl;

    cout << "Right Child: ";
    if (root->right != NULL)
        cout << root->right->name;
    else
        cout << "None";

    cout << "\n-------------------\n";

    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    Node* grandfather = new Node("Grandfather");
    Node* grandmother = new Node("Grandmother");
    Node* father = new Node("Father");
    Node* uncle = new Node("Uncle");
    Node* child1 = new Node("Ali");
    Node* child2 = new Node("Sara");
    Node* cousin = new Node("Ahmed");

    grandfather->left = grandmother;
    grandfather->right = father;

    grandmother->left = uncle;
    grandmother->right = cousin;

    father->left = child1;
    father->right = child2;

    cout << "Family Tree Information\n";
    cout << "=======================\n";
    displayTree(grandfather);

    delete child1;
    delete child2;
    delete cousin;
    delete uncle;
    delete father;
    delete grandmother;
    delete grandfather;

    return 0;
}

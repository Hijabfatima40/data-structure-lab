#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};
void display(Node* root) {
    if (root == NULL)
        return;

    cout << "Member: " << root->name << endl;

    if (root->left != NULL)
        cout << "Left Child: " << root->left->name << endl;
    else
        cout << "Left Child: None" << endl;

    if (root->right != NULL)
        cout << "Right Child: " << root->right->name << endl;
    else
        cout << "Right Child: None" << endl;

    cout << "------------------------" << endl;

    display(root->left);
    display(root->right);
}

int main() {
    Node* hod = new Node("Head of Department (HOD)");
    Node* c1 = new Node("Coordinator 1");
    Node* c2 = new Node("Coordinator 2");
    Node* f1 = new Node("Faculty Member 1");
    Node* f2 = new Node("Faculty Member 2");
    Node* f3 = new Node("Faculty Member 3");
    Node* f4 = new Node("Faculty Member 4");

    hod->left = c1;
    hod->right = c2;

    c1->left = f1;
    c1->right = f2;

    c2->left = f3;
    c2->right = f4;

    cout << "UNIVERSITY DEPARTMENT HIERARCHY" << endl;
    cout << "===============================" << endl;

    display(hod);

    return 0;
}


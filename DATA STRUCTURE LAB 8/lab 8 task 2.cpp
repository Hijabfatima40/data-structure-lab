
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string name) {
        category = name;
        left = NULL;
        right = NULL;
    }
};
void BFS(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    cout << "Product Categories (BFS Traversal):" << endl;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->category << endl;

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    Node* root = new Node("Electronics");

    Node* clothing = new Node("Clothing");
    Node* mobiles = new Node("Mobiles");
    Node* laptops = new Node("Laptops");
    Node* men = new Node("Men");
    Node* women = new Node("Women");
    Node* accessories = new Node("Accessories");

    root->left = clothing;
    root->right = mobiles;

    clothing->left = laptops;
    clothing->right = men;

    mobiles->left = women;
    mobiles->right = accessories;
    BFS(root);

    return 0;
}

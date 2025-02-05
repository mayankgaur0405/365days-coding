#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree() {  // No need to pass `root` as a parameter
    cout << "Enter the data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;  // Stop recursion immediately if -1 is entered
    }

    Node* root = new Node(data); // Create the node only if valid input is given

    cout << "Enter the left child of " << data << endl;
    root->left = buildTree();  // Recursively build the left subtree

    cout << "Enter the right child of " << data << endl;
    root->right = buildTree();  // Recursively build the right subtree

    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {  // Handle empty tree case
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main() {
    Node* root = buildTree();
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    return 0;
}

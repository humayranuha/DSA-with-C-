#include <iostream>
#include <cmath>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *newNode(int val) {
    return new Node(val);
}

bool isBalanced(Node *root, int *height) {
    if (root == NULL) {
        *height = 0;
        return true;
    }

    int leftHeight = 0, rightHeight = 0;

    bool leftBalanced = isBalanced(root->left, &leftHeight);
    bool rightBalanced = isBalanced(root->right, &rightHeight);

    *height = max(leftHeight, rightHeight) + 1;

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    return leftBalanced && rightBalanced;
}

int main() {
    int height = 0;
    
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    if (isBalanced(root, &height))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    return 0;
}
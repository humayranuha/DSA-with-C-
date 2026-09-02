// Checking if a binary tree is a full binary tree in C++ (Simple version)

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        key = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    // Create a new node
    Node *createNode(int value)
    {
        return new Node(value);
    }

    // Check if tree is full binary tree
    bool isFullBinaryTree(Node *root)
    {
        // Empty tree is full
        if (root == NULL)
            return true;

        // Leaf node has no children
        if (root->left == NULL && root->right == NULL)
            return true;

        // If both children exist, check recursively
        if (root->left != NULL && root->right != NULL)
        {
            return isFullBinaryTree(root->left) &&
                isFullBinaryTree(root->right);
        }

        // If one child exists but not the other
        return false;
    }
};

int main()
{
    BinaryTree tree;

    // Create tree
    Node *root = tree.createNode(1);
    root->left = tree.createNode(2);
    root->right = tree.createNode(3);
    root->left->left = tree.createNode(4);
    root->left->right = tree.createNode(5);
    root->left->right->left = tree.createNode(6);
    root->left->right->right = tree.createNode(7);

    // Check and display result
    if (tree.isFullBinaryTree(root))
        cout << "The tree is a full binary tree\n";
    else
        cout << "The tree is not a full binary tree\n";

    return 0;
}
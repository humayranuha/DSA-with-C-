// Checking if a binary tree is a perfect binary tree (Simple Class-based)

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

    // Calculate depth of tree
    int depth(Node *node)
    {
        if (node == NULL)
            return 0;

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // Check if perfect binary tree (recursive)
    bool isPerfectRecursive(Node *root, int depth, int level = 0)
    {
        if (root == NULL)
            return true;

        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return (depth == level + 1);

        // If one child exists but not the other
        if (root->left == NULL || root->right == NULL)
            return false;

        // Check both subtrees
        return isPerfectRecursive(root->left, depth, level + 1) &&
            isPerfectRecursive(root->right, depth, level + 1);
    }

    bool isPerfect(Node *root)
    {
        int d = depth(root);
        return isPerfectRecursive(root, d);
    }
};

int main()
{
    BinaryTree tree;

    // Create perfect binary tree
    Node *root = tree.createNode(1);
    root->left = tree.createNode(2);
    root->right = tree.createNode(3);
    root->left->left = tree.createNode(4);
    root->left->right = tree.createNode(5);
    root->right->left = tree.createNode(6);
    root->right->right = tree.createNode(7);

    if (tree.isPerfect(root))
        cout << "The tree is a perfect binary tree\n";
    else
        cout << "The tree is not a perfect binary tree\n";

    return 0;
}
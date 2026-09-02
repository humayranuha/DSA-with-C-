// Tree traversal in C++ (Simple & Clean)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class TreeTraversal
{
public:
    // Inorder: Left -> Root -> Right
    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder: Root -> Left -> Right
    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder: Left -> Right -> Root
    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main()
{
    // Create tree
    Node *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    TreeTraversal traversal;

    cout << "Inorder traversal:    ";
    traversal.inorder(root);
    cout << endl;

    cout << "Preorder traversal:   ";
    traversal.preorder(root);
    cout << endl;

    cout << "Postorder traversal:  ";
    traversal.postorder(root);
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
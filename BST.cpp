// Binary Search Tree operations in C++ (Simple Class-based)

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

class BST
{
private:
    Node *root;

public:
    // Constructor
    BST()
    {
        root = NULL;
    }

    // Create a new node
    Node *createNode(int item)
    {
        return new Node(item);
    }

    // Insert a node
    Node *insert(Node *node, int key)
    {
        if (node == NULL)
            return createNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        return node;
    }

    // Wrapper for insert
    void insert(int key)
    {
        root = insert(root, key);
    }

    // Find minimum value node
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    // Delete a node
    Node *deleteNode(Node *root, int key)
    {
        if (root == NULL)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            // Node with only one child or no child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    // Wrapper for delete
    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }

    // Inorder traversal
    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->key << " -> ";
            inorder(root->right);
        }
    }

    // Wrapper for inorder
    void inorder()
    {
        inorder(root);
        cout << "NULL" << endl;
    }

    // Get root
    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    BST tree;

    // Insert nodes
    tree.insert(8);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(7);
    tree.insert(10);
    tree.insert(14);
    tree.insert(4);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "After deleting 10\n";
    tree.deleteNode(10);
    cout << "Inorder traversal: ";
    tree.inorder();

    return 0;
}
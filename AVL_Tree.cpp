// Simple AVL Tree with Insertion and Deletion Examples

#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        key = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree
{
private:
    Node *root;

    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int balanceFactor(Node *node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    // Right Rotation (LL Case)
    Node *rightRotate(Node *y)
    {
        cout << "  Right rotation on " << y->key << endl;
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Left Rotation (RR Case)
    Node *leftRotate(Node *x)
    {
        cout << "  Left rotation on " << x->key << endl;
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = balanceFactor(node);

        // INSERTION CASES
        // LL Case
        if (balance > 1 && key < node->left->key)
        {
            cout << "  LL Imbalance at " << node->key << endl;
            return rightRotate(node);
        }

        // LR Case
        if (balance > 1 && key > node->left->key)
        {
            cout << "  LR Imbalance at " << node->key << endl;
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR Case
        if (balance < -1 && key > node->right->key)
        {
            cout << "  RR Imbalance at " << node->key << endl;
            return leftRotate(node);
        }

        // RL Case
        if (balance < -1 && key < node->right->key)
        {
            cout << "  RL Imbalance at " << node->key << endl;
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

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
            // Node found - DELETE IT
            cout << "  Deleting node " << key << endl;

            // Case 1: No child or one child
            if (root->left == NULL || root->right == NULL)
            {
                Node *temp = root->left ? root->left : root->right;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                // Case 2: Two children
                Node *temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == NULL)
            return root;

        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = balanceFactor(root);

        // DELETION CASES
        // LL Case
        if (balance > 1 && balanceFactor(root->left) >= 0)
        {
            cout << "  Deletion LL Imbalance at " << root->key << endl;
            return rightRotate(root);
        }

        // LR Case
        if (balance > 1 && balanceFactor(root->left) < 0)
        {
            cout << "  Deletion LR Imbalance at " << root->key << endl;
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RR Case
        if (balance < -1 && balanceFactor(root->right) <= 0)
        {
            cout << "  Deletion RR Imbalance at " << root->key << endl;
            return leftRotate(root);
        }

        // RL Case
        if (balance < -1 && balanceFactor(root->right) > 0)
        {
            cout << "  Deletion RL Imbalance at " << root->key << endl;
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void printTree(Node *root, string indent, bool last)
    {
        if (root != NULL)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }
            cout << root->key << endl;
            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void insert(int key)
    {
        cout << "\nInsert " << key << ":" << endl;
        root = insert(root, key);
        cout << "Tree:" << endl;
        printTree(root, "", true);
    }

    void remove(int key)
    {
        cout << "\nDelete " << key << ":" << endl;
        root = deleteNode(root, key);
        cout << "Tree:" << endl;
        printTree(root, "", true);
    }
};

int main()
{
    cout << "========== AVL TREE ROTATION EXAMPLES ==========" << endl << endl;

    // ===== SECTION 1: INSERTION EXAMPLES =====
    cout << endl;
    cout << "=================================================" << endl;
    cout << "         SECTION 1: INSERTION EXAMPLES" << endl;
    cout << "=================================================" << endl << endl;

    // Example 1: LL Case (Right Rotation)
    cout << "1. LL CASE - Insert 30, 20, 10" << endl;
    cout << "   (Causes LL imbalance at 30 - needs Right Rotation)" << endl;
    AVLTree tree1;
    tree1.insert(30);
    tree1.insert(20);
    tree1.insert(10);

    // Example 2: RR Case (Left Rotation)
    cout << "\n2. RR CASE - Insert 10, 20, 30" << endl;
    cout << "   (Causes RR imbalance at 10 - needs Left Rotation)" << endl;
    AVLTree tree2;
    tree2.insert(10);
    tree2.insert(20);
    tree2.insert(30);

    // Example 3: LR Case (Left-Right Rotation)
    cout << "\n3. LR CASE - Insert 30, 10, 20" << endl;
    cout << "   (Causes LR imbalance at 30 - needs Left then Right Rotation)" << endl;
    AVLTree tree3;
    tree3.insert(30);
    tree3.insert(10);
    tree3.insert(20);

    // Example 4: RL Case (Right-Left Rotation)
    cout << "\n4. RL CASE - Insert 10, 30, 20" << endl;
    cout << "   (Causes RL imbalance at 10 - needs Right then Left Rotation)" << endl;
    AVLTree tree4;
    tree4.insert(10);
    tree4.insert(30);
    tree4.insert(20);

    // ===== SECTION 2: DELETION EXAMPLES =====
    cout << endl << endl;
    cout << "=================================================" << endl;
    cout << "         SECTION 2: DELETION EXAMPLES" << endl;
    cout << "=================================================" << endl << endl;

    // Example 5: Deletion LL Case
    cout << "5. DELETION LL CASE" << endl;
    cout << "   (Delete from right subtree causes LL imbalance)" << endl;
    AVLTree tree5;
    cout << "Building tree: Insert 50, 30, 70, 20, 40, 60, 80" << endl;
    tree5.insert(50);
    tree5.insert(30);
    tree5.insert(70);
    tree5.insert(20);
    tree5.insert(40);
    tree5.insert(60);
    tree5.insert(80);
    tree5.remove(80);

    // Example 6: Deletion RR Case
    cout << "\n6. DELETION RR CASE" << endl;
    cout << "   (Delete from left subtree causes RR imbalance)" << endl;
    AVLTree tree6;
    cout << "Building tree: Insert 50, 30, 70, 20, 40, 60, 80" << endl;
    tree6.insert(50);
    tree6.insert(30);
    tree6.insert(70);
    tree6.insert(20);
    tree6.insert(40);
    tree6.insert(60);
    tree6.insert(80);
    tree6.remove(20);

    // Example 7: Deletion LR Case
    cout << "\n7. DELETION LR CASE" << endl;
    cout << "   (Delete from right subtree causes LR imbalance)" << endl;
    AVLTree tree7;
    cout << "Building tree: Insert 50, 30, 70, 20, 40, 60" << endl;
    tree7.insert(50);
    tree7.insert(30);
    tree7.insert(70);
    tree7.insert(20);
    tree7.insert(40);
    tree7.insert(60);
    tree7.remove(60);

    // Example 8: Deletion RL Case
    cout << "\n8. DELETION RL CASE" << endl;
    cout << "   (Delete from left subtree causes RL imbalance)" << endl;
    AVLTree tree8;
    cout << "Building tree: Insert 50, 30, 70, 40, 60, 80" << endl;
    tree8.insert(50);
    tree8.insert(30);
    tree8.insert(70);
    tree8.insert(40);
    tree8.insert(60);
    tree8.insert(80);
    tree8.remove(30);

    // ===== SECTION 3: COMPLEX EXAMPLE =====
    cout << endl << endl;
    cout << "=================================================" << endl;
    cout << "         SECTION 3: COMPLEX EXAMPLE" << endl;
    cout << "=================================================" << endl << endl;

    cout << "9. COMPLEX - Multiple Insertions and Deletions" << endl;
    AVLTree tree9;
    cout << "Insert: 10, 20, 30, 40, 50, 25" << endl;
    tree9.insert(10);
    tree9.insert(20);
    tree9.insert(30);
    tree9.insert(40);
    tree9.insert(50);
    tree9.insert(25);

    cout << "\nDelete: 10, 40, 25" << endl;
    tree9.remove(10);
    tree9.remove(40);
    tree9.remove(25);

    cout << endl;
    cout << "=================================================" << endl;
    cout << "              END OF DEMONSTRATION" << endl;
    cout << "=================================================" << endl;

    return 0;
}
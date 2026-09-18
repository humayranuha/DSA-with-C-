// Simple Huffman Coding in C++

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Huffman tree node
struct Node
{
    char ch;  // Character
    int freq; // Frequency
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare function for min-heap (smallest frequency first)
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Print Huffman codes by traversing the tree
void printCodes(Node *root, string code)
{
    if (root == NULL)
        return;

    // If leaf node, print character and its code
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << "  |  " << code << endl;
    }

    // Go left → add '0'
    printCodes(root->left, code + "0");

    // Go right → add '1'
    printCodes(root->right, code + "1");
}

// Build Huffman Tree and print codes
void huffmanCoding(char chars[], int freq[], int n)
{
    // Step 1: Create min-heap and insert all characters
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build the Huffman Tree
    while (pq.size() > 1)
    {
        // Extract two minimum frequency nodes
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create new internal node with combined frequency
        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Insert back into heap
        pq.push(newNode);
    }

    // Step 3: Print Huffman codes
    Node *root = pq.top();
    cout << "Char | Huffman Code" << endl;
    cout << "-------------------" << endl;
    printCodes(root, "");
}

int main()
{
    char chars[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 1, 6, 3};
    int n = sizeof(chars) / sizeof(chars[0]);

    cout << "Huffman Coding" << endl;
    cout << "==============" << endl;
    cout << "\nInput:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << chars[i] << ": " << freq[i] << endl;
    }
    cout << endl;

    huffmanCoding(chars, freq, n);

    return 0;
}
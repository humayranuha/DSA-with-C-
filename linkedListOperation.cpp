// Simple Linked List in C++

#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// LinkedList class
class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node
    void deleteNode(int value)
    {
        if (head == NULL)
            return;

        // If head needs to be deleted
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the node
        Node *temp = head;
        while (temp->next != NULL && temp->next->data != value)
        {
            temp = temp->next;
        }

        if (temp->next != NULL)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Search for a node
    bool search(int value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display the list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main()
{
    LinkedList list;

    // Insert elements
    list.insertAtEnd(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    list.insertAtEnd(4);

    cout << "Linked list: ";
    list.display();

    // Delete an element
    list.deleteNode(3);
    cout << "After deleting 3: ";
    list.display();

    // Search for an element
    cout << "Is 3 in list? " << (list.search(3) ? "Yes" : "No") << endl;
    cout << "Is 2 in list? " << (list.search(2) ? "Yes" : "No") << endl;

    return 0;
}
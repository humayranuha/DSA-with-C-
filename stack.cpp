#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> items;
    const int MAX = 10;

public:
    bool isFull() const
    {
        return items.size() == MAX;
    }

    bool isEmpty() const
    {
        return items.empty();
    }

    void push(int newItem)
    {
        if (isFull())
        {
            cout << "Stack is full!!!" << endl;
        }
        else
        {
            items.push_back(newItem);
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!!!" << endl;
        }
        else
        {
            cout << "Item popped= " << items.back() << endl;
            items.pop_back();
        }
    }

    void print() const
    {
        cout << "Stack: ";
        for (int item : items)
        {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.print();

    s.pop();

    s.print();

    return 0;
}
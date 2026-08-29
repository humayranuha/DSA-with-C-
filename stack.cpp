#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 10  

// Creating a stack
struct stack
{
    int items[MAX];
    int top;
};

void createEmptyStack(stack *s)
{
    s->top = -1;
}

// Check if the stack is full
int isFull(stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if the stack is empty
int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Add elements into stack
void push(stack *s, int newItem)
{
    if (isFull(s))
    {
        cout << "Stack is full!!!" << endl;
    }
    else
    {
        s->top++;
        s->items[s->top] = newItem;
    }
}

// Remove element from stack
void pop(stack *s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty!!!" << endl;
    }
    else
    {
        cout << "Item popped= " << s->items[s->top] << endl;
        s->top--;
    }
}

// Print elements of stack
void printStack(stack *s)
{
    cout << "Stack: ";
    for (int i = 0; i <= s->top; i++)  
    {
        cout << s->items[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    stack *s = (stack *)malloc(sizeof(stack));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    printStack(s);

    free(s);  // Clean up memory
    return 0;
}
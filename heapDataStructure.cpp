#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down - moves element down the tree
void heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && hT[left] > hT[largest])
        largest = left;
    if (right < size && hT[right] > hT[largest])
        largest = right;

    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}

// Insert element
void insert(vector<int> &hT, int num)
{
    hT.push_back(num);
    int i = hT.size() - 1;

    // Bubble up
    while (i > 0 && hT[i] > hT[(i - 1) / 2])
    {
        swap(&hT[i], &hT[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete element
void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;

    // Find the element
    for (i = 0; i < size; i++)
    {
        if (hT[i] == num)
            break;
    }

    if (i == size)
    {
        cout << "Element not found!" << endl;
        return;
    }

    // Swap with last and remove
    swap(&hT[i], &hT[size - 1]);
    hT.pop_back();

    // Fix the heap
    if (i < hT.size())
    {
        // Check if we need to bubble up or down
        if (i > 0 && hT[i] > hT[(i - 1) / 2])
            while (i > 0 && hT[i] > hT[(i - 1) / 2])
            {
                swap(&hT[i], &hT[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        else
            heapify(hT, i);
    }
}

// Print array
void print(vector<int> &hT)
{
    for (int x : hT)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> heap;

    cout << "Inserting: 3, 4, 9, 5, 2" << endl;
    insert(heap, 3);
    insert(heap, 4);
    insert(heap, 9);
    insert(heap, 5);
    insert(heap, 2);

    cout << "Heap: ";
    print(heap);

    cout << "\nDeleting: 4" << endl;
    deleteNode(heap, 4);
    cout << "Heap: ";
    print(heap);

    cout << "\nDeleting: 9" << endl;
    deleteNode(heap, 9);
    cout << "Heap: ";
    print(heap);

    cout << "\nInserting: 7" << endl;
    insert(heap, 7);
    cout << "Heap: ";
    print(heap);

    return 0;
}
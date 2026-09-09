#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int size)
{
    cout << "Starting Selection Sort:\n"
        j<< endl;

    for (int step = 0; step < size - 1; step++)
    {
        cout << "Pass " << step + 1 << ":" << endl;
        cout << "  Array before: ";
        printArray(array, size);

        int min_idx = step;
        cout << "  Finding minimum from index " << step << " to " << size - 1 << endl;

        for (int i = step + 1; i < size; i++)
        {
            cout << "    Compare " << array[i] << " and " << array[min_idx];
            if (array[i] < array[min_idx])
            {
                min_idx = i;
                cout << " → New minimum at index " << min_idx << " (" << array[min_idx] << ")" << endl;
            }
            else
            {
                cout << " → No change" << endl;
            }
        }

        cout << "  Minimum element: " << array[min_idx] << " at index " << min_idx << endl;
        cout << "  Swapping " << array[step] << " and " << array[min_idx] << endl;
        swap(&array[min_idx], &array[step]);

        cout << "  Array after pass " << step + 1 << ": ";
        printArray(array, size);
        cout << endl;
    }
}

int main()
{
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array: ";
    printArray(data, size);
    cout << endl;

    selectionSort(data, size);

    cout << "Sorted array in Ascending Order:\n";
    printArray(data, size);

    return 0;
}
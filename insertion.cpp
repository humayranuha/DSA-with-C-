#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int array[], int size)
{
    cout << "Starting Insertion Sort:\n"
        << endl;

    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        cout << "Step " << step << ": Insert " << key << endl;
        cout << "  Array before: ";
        printArray(array, size);
        cout << "  Comparing " << key << " with elements to the left:" << endl;

        while (j >= 0 && key < array[j])
        {
            cout << "    " << key << " < " << array[j] << "  Shift " << array[j] << " right" << endl;
            array[j + 1] = array[j];
            --j;
        }

        if (j >= 0)
        {
            cout << "    " << key << " > " << array[j] << "  Stop" << endl;
        }
        else
        {
            cout << "    Reached beginning of array" << endl;
        }

        array[j + 1] = key;
        cout << "  Array after: ";
        printArray(array, size);
        cout << endl;
    }
}

int main()
{
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array: ";
    printArray(data, size);
    cout << endl;

    insertionSort(data, size);

    cout << "Sorted array in ascending order:\n";
    printArray(data, size);

    return 0;
}
#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    cout << "Starting Bubble Sort:\n" << endl;
    
    for (int step = 0; step < (size-1); ++step) {
        cout << "Pass " << step + 1 << ":" << endl;
        int swapped = 0;
        
        for (int i = 0; i < (size-step-1); ++i) {
            cout << "  Compare " << array[i] << " and " << array[i+1];
            
            if (array[i] > array[i + 1]) {
                cout << "  Swap" << endl;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            } else {
                cout << "  No swap" << endl;
            }
        }
        
        cout << "  Array after pass " << step + 1 << ": ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        
        if (swapped == 0) {
            cout << "  No swaps in this pass  Array is sorted!" << endl;
            break;
        }
        cout << endl;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}

int main() {
    int data[] = {-2, 45, 0, 11, -9};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "Original array:";
    printArray(data, size);
    cout << endl;
    
    bubbleSort(data, size);
    
    cout << "\nSorted Array in Ascending Order:";
    printArray(data, size);
    
    return 0;
}
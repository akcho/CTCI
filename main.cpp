#include <iostream>
using namespace std;

/* This function sets the last element as pivot, places the pivot at its correct position in a sorted array, and
 * places elements smaller than the pivot to its left and greater than the pivot to its right*/
int Partition (int arr[], int low, int high) {
    int pivot = arr[high]; // pivot == the last element in the array
    int i = low; // set i as the first element

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {    // If current element is smaller than pivot
            swap(arr[i], arr[j]);
            i++;
        }
    }
    cout << "pivot == " << pivot << endl;
    cout << "i == " << i << ", arr[i] == " << arr[i] << endl;
    cout << "high == " << high << ", arr[high] == " << arr[high] << endl << endl;
    swap(arr[i], arr[high]);
    return i;
}

void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int partition_index = Partition(arr, low, high);    // swaps elements when necessary
        QuickSort(arr, low, partition_index - 1);   // sort left side
        QuickSort(arr, partition_index + 1, high);  // sort right side
    }
}

/* Function to print an array */
void PrintArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    PrintArray(arr, n);
    return 0;
}
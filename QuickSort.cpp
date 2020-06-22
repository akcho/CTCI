#include <iostream>
using namespace std;

/* Function to print an array */
void PrintArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int Partition (int arr[], int left, int right) {
    int pivot = arr[left + (right - left) / 2];    // arbitrary pivot point
    while (left <= right) {
        while (arr[left] < pivot) left++;   // iterate until you find an element that should be on the right
        while (arr[right] > pivot) right--;    // decrement until you find an element that should be on the left
        if (left <= right) {    // we have two elements that should swap sides
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void QuickSort(int arr[], int left, int right) {
        int partition_index = Partition(arr, left, right);    // swaps elements when necessary
        if (left < partition_index - 1) QuickSort(arr, left, partition_index - 1);   // sort left side
        if (partition_index < right) QuickSort(arr, partition_index, right);  // sort right side
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
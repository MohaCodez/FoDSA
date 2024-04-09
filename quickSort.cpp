#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as pivot
    int i = low - 1; // Index of smaller element
    
    for (int j = low; j < high; ++j) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Swap arr[i + 1] and arr[high] (pivot)
    return i + 1; // Return the partition index
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

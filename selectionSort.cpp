#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        
        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    selectionSort(arr);
    
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

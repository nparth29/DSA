#include <iostream>
using namespace std;

void traverseArray(int arr[], int size, int index = 0) {
    if (index == size) // Base case: if index reaches size, stop
        return;

    cout << arr[index] << " "; // Print current element
    traverseArray(arr, size, index + 1); // Recursive call for next element
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array elements: ";
    traverseArray(arr, n); // Start recursion from index 0

    return 0;
}

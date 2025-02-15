#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize the vector with unsorted elements
    vector<int> v = {4,4,2,1};
    int n = v.size();  // Get the size of the vector

    // Display the original array
    cout << "Your original array is: ";
    for (int element : v) {
        cout << element << " ";  // Print each element of the vector
    }
    cout << endl;

    // Start the insertion sort algorithm
    // The outer loop iterates over each element starting from index 1, as the first element is already "sorted"
    for (int i = 1; i < n; i++) {
        int j = i;  // Initialize `j` to the current index to begin comparisons
        // Traverse the sorted portion of the array backwards to find the correct position for v[i]
        while (j >= 1 && v[j] < v[j - 1]) {
            // Swap elements if the current element is smaller than the previous element
            swap(v[j], v[j - 1]);
            j--;  // Move one step back to continue comparisons
        }

        // Extra step: Display the array after each iteration for better understanding of the sorting process
        cout << "Your array after " << i << "'th iteration is: ";
        for (int k = 0; k < n; k++) {
            cout << v[k] << " ";  // Print each element of the array
        }
        cout << endl;
    }

    // Display the final sorted array
    cout << "Your array after applying insertion sort is: ";
    for (int element : v) {
        cout << element << " ";  // Print each element of the sorted vector
    }
    cout << endl;

    return 0;
}

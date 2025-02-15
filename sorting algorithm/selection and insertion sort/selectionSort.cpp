#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    // Initialize the vector with unsorted elements
    vector<int> v = {5, 3, 1, 4, 2};
    int n = v.size();  // Get the size of the vector

    // Display the original array
    cout << "Your original array is : ";
    for (int element : v) {
        cout << element << " ";  // Print each element of the vector
    }
    cout << endl;

    // Selection Sort Algorithm
    // Outer loop: The outer loop runs n-1 times (since the last element will be automatically sorted)
    for (int i = 0; i < n - 1; i++) {                 // Total number of iterations is n-1
        int min = INT_MAX;                             // Initialize 'min' to the largest possible value (to find the minimum)
        int minIdx = -1;                               // 'minIdx' holds the index of the minimum element found so far
        // Inner loop: Start comparing elements from the current 'i' to the end of the vector
        // This ensures that each pass looks for the minimum in the unsorted part of the array
        for (int j = i; j < n; j++) {                  // Inner loop runs from i to n
            // If the current element v[j] is smaller than the current 'min', update 'min' and 'minIdx'
            if (v[j] < min) {                          
                min = v[j];                             // Update the minimum value
                minIdx = j;                            // Store the index of the new minimum value
            }
        }
        // Swap the smallest found element with the element at index 'i'
        // This places the smallest element at the beginning of the unsorted portion of the array
        swap(v[i], v[minIdx]);                         // Swap the found minimum element with v[i]
        // iterations :
        cout<<"For "<<i<<"'th "<<" iteration the array is like : ";
        for(int k=0;k<n;k++){
          cout<<v[k]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    // Display the sorted array after sorting is complete
    cout << "Your array after sorting: ";
    for (int element : v) {
        cout << element << " ";  // Print the sorted array
    }
    cout << endl;

    return 0;
}

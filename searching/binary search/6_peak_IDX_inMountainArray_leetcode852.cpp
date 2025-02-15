#include <iostream>
using namespace std;

int peakIndexInMountainArray(int arr[], int n) {
    // Step 1: Initialize search space
    int lo = 1;        // Start from index 1 (avoid out-of-bounds for arr[mid-1])
    int hi = n - 2;    // End at index n-2 (avoid out-of-bounds for arr[mid+1])
    
    // Step 2: Apply Binary Search
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Calculate middle index to avoid overflow
        
        // Step 3: Check if mid is the peak
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;  // Peak found, return index
        }

        // Step 4: If we are on a decreasing slope, move left
        else if (arr[mid] > arr[mid + 1]) {
            hi = mid - 1;
        }

        // Step 5: If we are on an increasing slope, move right
        else {
            lo = mid + 1;
        }
    }

    // Step 6: Return -1 (Though this case won't occur as per problem constraints)
    return -1;
}

// Driver code to test the function
int main() {
    int arr[] = {0, 2, 5, 7, 8, 6, 3, 1};  // Example Mountain Array
    int n = sizeof(arr) / sizeof(arr[0]);  // Get size of the array

    int peakIndex = peakIndexInMountainArray(arr, n); // Find the peak index

    cout << "Peak Index: " << peakIndex << endl;  // Print the peak index
    return 0;
}

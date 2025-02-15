/*
    given an array with N distinct elements, convert the given array to a form  where all
    elements are in the range from 0 to N-1. The order of elements is the same i.e., 0 is 
    placed in the place of the smallest element, 1 is placed for the second smallest 
    , ... N-1 is placed for the largest element.
*/


#include <iostream>
#include <vector>
#include <climits> // For INT_MAX, to handle large values
using namespace std;

int main() {
    // Step 1: Initialize the vector with unsorted elements
    // Example input: An array of 5 distinct elements.
    vector<int> nums = {19, 12, 23, 8, 16};
    
    // Step 2: Create a vector 'v' to keep track of whether an index has been visited or not.
    // We initialize the 'v' vector with 0 (not visited). Size of 'v' is the same as 'nums'.
    vector<int> v(5, 0); // Value 0 means the element at this index is not yet processed.
    
    // Step 3: Define the number of elements in the array.
    int n = nums.size();
    
    // Step 4: Initialize 'x' to 0, which will be used to assign ranks (0 to N-1) to the elements.
    int x = 0; // This will represent the rank of each element in the sorted order.

    // Step 5: Main loop that will run for each element in the array
    for (int i = 0; i < n; i++) {
        // Step 6: Find the smallest unvisited element in the array.
        int min = INT_MAX;  // Initialize 'min' to the largest possible integer, INT_MAX.
        int minIdx = -1;    // This will store the index of the minimum element.

        // Step 7: Loop through the array to find the smallest unvisited element.
        // We skip any element that has already been visited by checking 'v[j] == 1'.
        for (int j = 0; j < n; j++) {
            if (v[j] == 1) continue; // Skip if the element at index 'j' has already been assigned a rank.

            // Step 8: If the current element 'nums[j]' is smaller than 'min', update 'min' and 'minIdx'.
            if (nums[j] < min) {
                min = nums[j];       // Update the minimum value found.
                minIdx = j;          // Store the index of the minimum value.
            }
        }

        // Step 9: After finding the minimum element, assign the rank 'x' to this element in the 'nums' array.
        nums[minIdx] = x;     // Replace the smallest element with its corresponding rank.
        v[minIdx] = 1;        // Mark this index as visited, so we don't process it again.
        x++;                  // Increment the rank for the next element.
    }

    // Step 10: Print the modified 'nums' array after assigning ranks.
    // Now, each element in 'nums' will be replaced with a number between 0 and N-1
    // according to their sorted order.
    cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";  // Print each element in the modified 'nums' array.
    }
    cout << endl;  // Print a newline at the end.

    return 0;  // Return 0 to indicate the program executed successfully.
}








/*
method 2 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> convertToRange(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Create a vector of pairs (value, original index)
    vector<pair<int, int>> valueIndexPairs;
    for (int i = 0; i < n; i++) {
        valueIndexPairs.push_back({arr[i], i});
    }

    // Step 2: Sort the pairs based on the values
    sort(valueIndexPairs.begin(), valueIndexPairs.end());

    // Step 3: Create a result array to store ranks
    vector<int> result(n);
    for (int rank = 0; rank < n; rank++) {
        int originalIndex = valueIndexPairs[rank].second; // Get the original index
        result[originalIndex] = rank; // Assign rank
    }

    return result;
}

int main() {
    // Example input
    vector<int> arr = {40, 10, 20, 30};

    // Convert the array
    vector<int> converted = convertToRange(arr);

    // Output the result
    cout << "Converted array: ";
    for (int val : converted) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}




*/
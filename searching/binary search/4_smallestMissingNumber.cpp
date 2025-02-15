#include <iostream>
#include <vector>

using namespace std;

// Method 1: Using Two Pointers (Efficient O(n) Approach)
int findSmallestMissing_1(vector<int> &v) {
    int n = v.size();
    int i = 0, k = 0;  // `i` is the expected number, `k` is the index in array

    while (k < n) {
        if (v[k] == i) {
            i++;  // Move to the next expected number
            k++;  // Move to the next element in the array
        } 
        else {
            return i;  // Return the first missing number
        }
    }
    return i;  // If no missing number found, return the next expected number
}

// Method 2: Simple Iteration (O(n) Approach)
int findSmallestMissing_2(vector<int> &v) {
    int n = v.size();
    
    for (int i = 0; i < n; i++) {
        if (i != v[i]) return i;  // First mismatch found
    }
    return n;  // If all numbers are in sequence, return next expected number
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 8, 9, 12};  // Sorted array with missing numbers

    // Calling both methods
    cout << "Method 1 - Smallest missing number: " << findSmallestMissing_1(v) << endl;
    cout << "Method 2 - Smallest missing number: " << findSmallestMissing_2(v) << endl;

    return 0;
}

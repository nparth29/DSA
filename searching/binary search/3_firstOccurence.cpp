#include <iostream>
#include <vector>
using namespace std;

// We have to find the first occurrence of the number in the given sorted array.
int main() {
    // Step 1: Initialize the sorted vector
    vector<int> v = {1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 5, 5, 9};
    int n = v.size();  // Get the size of the vector
    int x = 5;  // The target number we want to find the first occurrence of

    // Step 2: Initialize binary search variables
    int flag = false;  // Flag to check if x is found
    int lo = 0, hi = n - 1;  // Binary search boundaries

    // Step 3: Perform binary search
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // Compute mid index to avoid overflow

        if (v[mid] == x) {
            // Step 4: Check if it's the first occurrence
            if (mid == 0 || v[mid - 1] != x) {  // Ensure mid-1 is not out of bounds
                flag = true;
                cout << "The first occurrence of " << x << " is at index: " << mid << endl;
                break;
            } else {
                // If v[mid-1] is also x, move left to find the first occurrence
                hi = mid - 1;
            }
        } 
        else if (v[mid] < x) {
            // Step 5: If x is greater, move right
            lo = mid + 1;
        } 
        else {
            // Step 6: If x is smaller, move left
            hi = mid - 1;
        }
    }

    // Step 7: If x is not found, print -1
    if (!flag)
        cout << "-1 (Element not found in the array)" << endl;

    return 0;
}

             // v[mid-1] == x     mean index of arr[mid] is not the answer because x is also present at the just right of mid
            //   so the the index of mid and its right part is of no use so we put hi = mid-1 coz there is a chance that mid -1 may be the first index 
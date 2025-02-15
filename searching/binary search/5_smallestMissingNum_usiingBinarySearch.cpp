#include <iostream>
#include <vector>

using namespace std;

// Method 3: Binary Search Approach (O(log n))
int findSmallestMissing_BS(vector<int> &v) {
    int lo = 0, hi = v.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (v[mid] == mid) {
            // If v[mid] == mid, missing number is in the right half
            lo = mid + 1;
        } 
        else {
            // Otherwise, the missing number is in the left half (or could be mid itself)
            hi = mid - 1;
        }
    }

    // The first index where `i != v[i]` is our missing number
    return lo;
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 8, 9, 12};  // Sorted array with missing numbers

    // Calling Binary Search method
    cout << "Binary Search - Smallest missing number: " << findSmallestMissing_BS(v) << endl;

    return 0;
}

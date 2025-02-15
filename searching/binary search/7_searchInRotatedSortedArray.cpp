#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        // Step 1: Find the pivot point (smallest element in rotated array)
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;  // Pivot is in the right half
            } else {
                hi = mid;  // Pivot is in the left half (including mid)
            }
        }

        int pivot = lo; // Smallest element index (pivot)
        lo = 0, hi = n - 1;

        // Step 2: Determine which half to search in
        if (target >= nums[pivot] && target <= nums[hi]) {
            lo = pivot;  // Search in the rotated right half
        } else {
            hi = pivot - 1;  // Search in the left half
        }

        // Step 3: Perform binary search
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;  // Target found
            } else if (nums[mid] < target) {
                lo = mid + 1;  // Move right
            } else {
                hi = mid - 1;  // Move left
            }
        }

        return -1;  // Target not found
    }
};

// Main function for testing
int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};  // Rotated sorted array
    int target = 0;

    int result = solution.search(nums, target);
    
    if (result != -1) {
        cout << "Target " << target << " found at index: " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}

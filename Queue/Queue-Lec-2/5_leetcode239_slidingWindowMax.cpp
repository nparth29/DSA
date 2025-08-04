#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;

        int n = nums.size();
        deque<int> dq;  // stores *indices* of useful elements in window
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // 1. Maintain decreasing order: remove all smaller elements from back
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();

            // 2. Push current index
            dq.push_back(i);

            // 3. Remove indices out of current window
            int j = i - k + 1;  // left boundary of window
            if (!dq.empty() && dq.front() < j)
                dq.pop_front();

            // 4. Add max of current window to result (start from when window is full)
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// Sample main function to test
int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);
    cout << "Max in each sliding window of size " << k << ":\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

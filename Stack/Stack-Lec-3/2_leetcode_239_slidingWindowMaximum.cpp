#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    // Brute Force Method
    vector<int> maxSlidingWindowBruteForce(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            int maxElem = -1e9;
            for (int j = i; j < i + k; j++) {
                maxElem = max(maxElem, arr[j]);
            }
            ans.push_back(maxElem);
        }
        return ans;
    }

    // Next Greater Index Jumping Method
    vector<int> maxSlidingWindowNGI(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ngi(n);
        stack<int> st;

        ngi[n - 1] = n;  // No greater element to the right
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            int j = i;
            while (ngi[j] < i + k) {
                j = ngi[j];
            }
            ans.push_back(arr[j]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution sol;

    vector<int> bruteResult = sol.maxSlidingWindowBruteForce(nums, k);
    cout << "Brute Force Output: ";
    for (int val : bruteResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> ngiResult = sol.maxSlidingWindowNGI(nums, k);
    cout << "NGI Jumping Output: ";
    for (int val : ngiResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

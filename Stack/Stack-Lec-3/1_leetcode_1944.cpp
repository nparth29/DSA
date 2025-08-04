#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {  // arr represents height
        int n = arr.size();
        vector<int> ans(n, 0);   // initialize all answer values to 0
        stack<int> st;

        ans[n - 1] = 0;          // last person can’t see anyone
        st.push(arr[n - 1]);     // push last person into stack

        // traverse from second last to first
        for (int i = n - 2; i >= 0; i--) {
            int count = 0;

            // keep popping while top is shorter than current person
            while (st.size() > 0 && st.top() < arr[i]) {
                st.pop();      // person can see the shorter one
                count++;       // increase visible count
            }

            // if someone taller remains, he is still visible (but blocks further)
            if (st.size() != 0) count++;

            ans[i] = count;    // store count in answer
            st.push(arr[i]);   // push current person for future comparisons
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of people in queue: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of people:\n";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    Solution sol;
    vector<int> result = sol.canSeePersonsCount(heights);

    cout << "Number of people each person can see:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        vector<int> nsi(n);  // Next Smaller Index
        nsi[n - 1] = n;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nsi[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> psi(n);  // Previous Smaller Index
        stack<int> pt;
        psi[0] = -1;
        pt.push(0);

        for (int i = 1; i < n; i++) {
            while (!pt.empty() && arr[pt.top()] >= arr[i]) {
                pt.pop();
            }
            psi[i] = pt.empty() ? -1 : pt.top();
            pt.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int height = arr[i];
            int breadth = nsi[i] - psi[i] - 1;
            int area = height * breadth;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Input histogram: ";
    for (int h : heights) {
        cout << h << " ";
    }
    cout << endl;

    int result = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}

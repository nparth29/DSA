#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < n;i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }

        // comparison
        int i = 0;
        while(i <= n-k){    
            while(q.size() >0 && q.front() < i) q.pop();
            if(q.size() == 0 || q.front() >=i+k) ans.push_back(0);
            else ans.push_back(arr[q.front()]);
            i++;
        }
        return ans;
    }
};

// Sample test for local testing (not part of LeetCode submission)
int main() {
    Solution sol;
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    cout << "array :";
    for (int i = 0; i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> result = sol.firstNegativeInWindow(arr, k);

    cout << "First negatives in each window of size " << k << ":\n";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}

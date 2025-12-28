#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        // Frequency map to store count of each digit
        unordered_map<int, int> m;
        for (int ele : arr) {
            m[ele]++;
        }

        // Iterate through all 3-digit even numbers
        for (int i = 100; i <= 999; i += 2) {

            int x = i;

            // Extract digits
            int a = x % 10;   // units digit (must be even)
            x /= 10;
            int b = x % 10;   // tens digit
            x /= 10;
            int c = x;        // hundreds digit

            // Check availability of digit 'a'
            if (m.find(a) != m.end()) {
                m[a]--;
                if (m[a] == 0) m.erase(a);

                // Check availability of digit 'b'
                if (m.find(b) != m.end()) {
                    m[b]--;
                    if (m[b] == 0) m.erase(b);

                    // Check availability of digit 'c'
                    if (m.find(c) != m.end()) {
                        ans.push_back(i);  // valid even number formed
                    }

                    // Restore digit 'b'
                    m[b]++;
                }

                // Restore digit 'a'
                m[a]++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {2, 1, 3, 0};

    // Call function
    vector<int> result = sol.findEvenNumbers(arr);

    // Output result
    cout << "Even 3-digit numbers formed: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

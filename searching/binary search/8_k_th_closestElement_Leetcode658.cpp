#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans(k);
        
        // case 1 when x is < arr[0]
        if (x < arr[0]) {
            for (int i = 0; i < k; i++) {
                ans[i] = arr[i];
            }
            return ans;
        }

        // case 2 when x is > arr[n-1]
        if (x > arr[n - 1]) {
            int j = k - 1;
            int i = n - 1;
            while (j >= 0) {
                ans[j] = arr[i];
                i--;
                j--;
            }
            return ans;
        }

        // actual code 
        // finding the lower bound and upper bound of the array 
        int lo = 0;
        int hi = n - 1;
        int mid = -1;
        int t = 0; 
        bool flag = false; // we have considered that x is not present in the array 

        // binary search 
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (arr[mid] == x) {
                flag = true;
                ans[t] = arr[mid]; // ans[0] = ans[x] itself because x is closer to itself
                t++; // initially t is 0 now we put x in ans array so t++ coz it is used in traversing in ans
                break;
            } else if (arr[mid] > x) hi = mid - 1;
            else lo = mid + 1;
        }

        // when loop breaks hi is our lower bound(lb) and lo is upper bound if x is not present in the array
        int lb = hi;
        int ub = lo;
        if (flag == true) {
            lb = mid - 1;
            ub = mid + 1;
        }

        // now we have to insert the elements into the ans array 
        while (t < k && lb >= 0 && ub <= n - 1) { 
            // we have to find the difference 
            int d1 = abs(x - arr[lb]);
            int d2 = abs(x - arr[ub]);

            if (d1 <= d2) {
                ans[t] = arr[lb];
                // t++;
                lb--;
            } else {  // d1 > d2 means ub is closer to x as compared to lb
                ans[t] = arr[ub];
                // t++;
                ub++;
            }
            t++;  // common in both if and else so we have written it separately 
        }

        // if lb crosses the order means lb < 0
        if (lb < 0) {
            while (t < k) {
                ans[t] = arr[ub];
                t++;
                ub++;
            }
        }
        if (ub > n - 1) {
            while (t < k) {
                ans[t] = arr[lb];
                t++;
                lb--;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    // Calling the function and storing the result
    vector<int> result = sol.findClosestElements(arr, k, x);

    // Output the result
    cout << "The closest " << k << " elements to " << x << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

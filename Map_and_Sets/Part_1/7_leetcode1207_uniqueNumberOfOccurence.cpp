#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // map to store number -> frequency
        unordered_map<int,int> m;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }

        // set to store unique frequencies
        unordered_set<int> s;
        for(auto x : m){
            int freq = x.second;

            // if frequency already exists, return false
            if(s.find(freq) != s.end()) return false;

            s.insert(freq);
        }

        // no duplicate frequencies found
        return true;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {1,2,2,1,1,3};
    vector<int> arr2 = {1,2};
    vector<int> arr3 = {-3,0,1,-3,1,1,1,-3,10,0};

    cout << boolalpha;
    cout << "arr1 -> " << obj.uniqueOccurrences(arr1) << endl; // true
    cout << "arr2 -> " << obj.uniqueOccurrences(arr2) << endl; // false
    cout << "arr3 -> " << obj.uniqueOccurrences(arr3) << endl; // true

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];

            // check if the remaining is present in map or not
            if(map.find(rem) != map.end()){
                // if present, push back both indexes into ans
                ans.push_back(map[rem]); // index of rem
                ans.push_back(i);        // index of nums[i]
            }
            else {
                // if not found, store the value with its index
                map[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 7, 11, 15, 3, 6};
    int target = 9;

    vector<int> result = obj.twoSum(nums, target);

    cout << "Indexes: ";
    for(int idx : result){
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, int idx, vector<int> current, vector<vector<int>>& result) {
    if (idx == nums.size()) {  
        result.push_back(current); // Store the current subset
        return;
    }

    // Exclude the current element
    generateSubsets(nums, idx + 1, current, result);

    // Include the current element
    current.push_back(nums[idx]);
    generateSubsets(nums, idx + 1, current, result);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> allSubsets = subsets(nums);

    // Printing all subsets
    cout << "Subsets:\n";
    for (auto subset : allSubsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
    return 0;
}

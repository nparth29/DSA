#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Function to find the majority element
int majorityElement(vector<int>& nums) {
    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Return the middle element (majority element)
    return nums[nums.size() / 2];
}

int main() {
    // Example input
    vector<int> nums = {3, 2, 3};

    // Find the majority element
    int result = majorityElement(nums);

    // Display the result
    cout << "The majority element is: " << result << endl;

    return 0;
}

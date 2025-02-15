#include <iostream>
#include <vector>
#include<climits> // For INT_MIN
using namespace std;

class Solution {
public:
    /**
     * Helper function to check if a given ship capacity 'mid' can ship all packages within 'days' days.
     */
    bool check(int mid, vector<int> &weights, int days) {
        int n = weights.size();
        int remainingCapacity = mid; // Ship's remaining capacity for the current day
        int dayCount = 1; // Start with 1 day
        
        // Iterate through all package weights
        for (int i = 0; i < n; i++) {
            if (remainingCapacity >= weights[i]) {
                // If the current package fits, subtract its weight from remaining capacity
                remainingCapacity -= weights[i];
                
            } else {
                // Otherwise, start a new shipping day
                dayCount++;
                remainingCapacity = mid; // Reset ship capacity for the new day
                remainingCapacity -= weights[i]; // Load the package on the new day
            }
        }

        // If we used more days than allowed, return false
        return dayCount <= days;
    }

    /**
     * Main function to find the minimum ship capacity required to transport all packages within 'days'.
     */
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxWeight = -1;
        int totalWeight = 0;

        // Calculate the maximum package weight and the total sum of weights
        for (int i = 0; i < n; i++) {
            maxWeight = max(maxWeight, weights[i]);
            totalWeight += weights[i];
        }

        // Binary search range: [maxWeight, totalWeight]
        int lo = maxWeight, hi = totalWeight;
        int minCapacity = totalWeight; // Store the minimum required capacity

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // Calculate mid (potential ship capacity)

            if (check(mid, weights, days)) {
                // If this capacity works, try to minimize further
                minCapacity = mid;
                hi = mid - 1;
            } else {
                // Otherwise, increase capacity
                lo = mid + 1;
            }
        }
        return minCapacity;
    }
};

int main() {
    Solution solution;
    vector<int> weights;
    int n, days;

    // Input: Number of packages
    cout << "Enter number of packages: ";
    cin >> n;
    weights.resize(n);
    
    // Input: Package weights
    cout << "Enter package weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    // Input: Number of days
    cout << "Enter number of days: ";
    cin >> days;

    // Compute and display the minimum ship capacity required
    int result = solution.shipWithinDays(weights, days);
    cout << "Minimum ship capacity required: " << result << endl;

    return 0;
}

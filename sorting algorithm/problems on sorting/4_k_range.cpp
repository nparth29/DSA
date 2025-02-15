// /*

// given an array arr[] containing n integers, the task i s to find an integer say k such that
// after replacing each & every index of the array by |ai -k| whrer i belongs to [1,n] result in a sorted array

// */


#include <iostream>
#include <vector>
#include <limits.h> // For INT_MIN and INT_MAX
using namespace std;

float max(float a, float b) {
    return (a >= b) ? a : b;
}

float min(float a, float b) {
    return (a < b) ? a : b;
}

int main() {
    vector<int> arr = {5, 3, 10, 3};
    int n = arr.size();
    bool flag = true;

    float kmin = -1e9; // Arbitrary large negative value
    float kmax = 1e9;  // Arbitrary large positive value

    // Compare arr[i] and arr[i + 1]
    for (int i = 0; i < n - 1; i++) { // Loop until n-1 to avoid out-of-bounds
        if (arr[i] >= arr[i + 1]) {
            // Update kmin
            kmin = max(kmin, (float)(arr[i] + arr[i + 1]) / 2);
        } else {
            // Update kmax
            kmax = min(kmax, (float)(arr[i] + arr[i + 1]) / 2);
        }

        // Check if kmin exceeds kmax
        if (kmin > kmax) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        cout << -1 << endl; // No valid k exists
    } else {
        // Handling kmin and kmax
        if (kmin == kmax) {
            if (kmin - (int)kmin == 0) {
                cout << "There is only one value of k: " << kmin << endl;
            } else {
                cout << -1 << endl; // No valid k exists since kmin is not an integer
            }
        } else {
            // Adjust kmin to the next integer if it's not already an integer
            if (kmin - (int)kmin > 0) {
                kmin = (int)kmin + 1;
            }

            // kmax is floored to the nearest integer
            cout << "Range of k is: [" << kmin << ", " << (int)kmax << "]" << endl;
        }
    }

    return 0;
}

#include <iostream>
using namespace std;
#include<climits>

int findMax(int arr[], int n, int idx) {
    if (idx == n) return -1; // Base case: if index reaches size, return minimum value.

    return max(arr[idx], findMax(arr, n, idx + 1)); // Compare current element with recursive result.
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum value: " << findMax(arr, n, 0) << endl;

    return 0;
}

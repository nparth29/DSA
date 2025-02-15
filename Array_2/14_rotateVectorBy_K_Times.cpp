//         index : 0  1  2  3  4  5  6
//         array : 1  6  2  3  7  4  8
//   let you hafer to rotate 2 shift mean k = 2;
// Algo : divide the array into two part  n-k and k where n is the size of array 
//                 1  6  2  3  7   &   4  8
//                 reverse the both part seperately 
//                 7  3  2  6  1  | 8  4
//                 reverse the whole array 
//                 4  8  1  6  2  3  7


// 1  6  2  3  7   &   4  8  -> index of 7 :(k-n-1) 
//                           -> index of 4 : (n-k)
//                           -> index of 8 : (n-1)


#include <iostream>
#include <vector>
using namespace std;

// Function to display a vector
void display(const vector<int> &b) {
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

// Function to reverse part of a vector
void reversePart(vector<int> &v, int i, int j) {
    while (i <= j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

// Main function to perform rotation
int main() {
    vector<int> v;
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Validate size
    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    // Input the array elements
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int arr;
        cin >> arr;
        v.push_back(arr);
    }

    cout << "Original vector: ";
    display(v);

    // Input the rotation index
    int k;
    cout << "Enter the number of positions to rotate to the right: ";
    cin >> k;

    // Handle edge cases
    if (k == 0 || k % n == 0) {
        cout << "Vector remains unchanged after rotation." << endl;
        display(v);
        return 0;
    }

    // Adjust k to be within bounds
    k = k % n;

    // Perform the rotation using reversal algorithm
    reversePart(v, 0, n - k - 1);  // Reverse the first part
    reversePart(v, n - k, n - 1);  // Reverse the second part
    reversePart(v, 0, n - 1);      // Reverse the entire vector

    cout << "Vector after rotation: ";
    display(v);

    return 0;
}

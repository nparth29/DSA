#include <iostream>
#include <vector>
using namespace std;

// Function to display the elements of the vector
void display(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to perform Bubble Sort on the vector
void bubbleSort(vector<int> &v) {
    int n = v.size();
    // Outer loop for the passes
    for (int i = 0; i < n - 1; i++) {
        bool flag = true; // Assume the array is sorted
        // Inner loop for comparisons in each pass
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) { 
                // Swap adjacent elements if they are in the wrong order
                swap(v[j], v[j + 1]);
                flag = false; // Mark that a swap occurred
            }
        }
        // If no swaps occurred in this pass, the array is already sorted
        if (flag == true) {
            break;
        }
    }
}

int main() {
    vector<int> v;
    int n;

    // Input: Size of the vector
    cout << "Enter the size of the vector: ";
    cin >> n;

    // Input: Elements of the vector
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // Display the original array
    cout << "Your original array is: " << endl;
    display(v);

    // Perform Bubble Sort
    bubbleSort(v);

    // Display the sorted array
    cout << "Sorted array is: " << endl;
    display(v);

    return 0;
}

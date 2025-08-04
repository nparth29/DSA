#include<iostream>
#include<stack>
using namespace std;

// FANDA :     pop , ans , push 
// Function to fill the Next Smaller Element array
void nextSmaller(int arr[], int n, int nse[]) {
    stack<int> st;

    // Last element always has no smaller to its right
    nse[n - 1] = -1;
    st.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        // Remove all elements from stack >= current element
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is empty, no smaller element
        if (st.empty())
            nse[i] = -1;
        else
            nse[i] = st.top();

        // Push current element to stack
        st.push(arr[i]);
    }
}

int main() {
    int arr[] = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int nse[n]; // Result array to store Next Smaller Elements

    // Call function
    nextSmaller(arr, n, nse);

    // Print input
    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print output
    cout << "Next Smaller Elements: ";
    for (int i = 0; i < n; i++) {
        cout << nse[i] << " ";
    }
    cout << endl;

    return 0;
}

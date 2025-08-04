#include<iostream>
#include<stack>
using namespace std;
// FANDA :     pop , ans , push 
// Function to fill the Next Greater Element array
void nextGreatest(int arr[], int n, int nge[]) {
    stack<int> st;
    
    // Last element always has no greater to its right
    nge[n - 1] = -1;
    st.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        // Remove all elements from stack <= current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element
        if (st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();

        // Push current element to stack
        st.push(arr[i]);
    }
}

int main() {
    int arr[] = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int nge[n]; // Result array to store Next Greater Elements

    // Call function
    nextGreatest(arr, n, nge);

    // Print input
    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print output
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}

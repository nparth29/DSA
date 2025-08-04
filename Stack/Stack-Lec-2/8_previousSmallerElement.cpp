#include<iostream>
#include<stack>
using namespace std;

// FANDA : pop , ans , push
void previousSmaller(int arr[], int n, int pse[]) {
    stack<int> st;

    pse[0] = -1;           // No element to the left of index 0
    st.push(arr[0]);       // Push first element

    for (int i = 1; i < n; i++) {
        // Pop until we find a smaller element or stack becomes empty
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        
        // Set answer
        if (st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }
}

int main() {
    int arr[] = {3, 1, 2, 5, 4, 6, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pse[n]; // Result array to store Previous Smaller Elements

    // Call function
    previousSmaller(arr, n, pse);

    // Print input
    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print output
    cout << "Previous Smaller Elements: ";
    for (int i = 0; i < n; i++) {
        cout << pse[i] << " ";
    }
    cout << endl;

    return 0;
}

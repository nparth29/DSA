#include<iostream>
#include<stack>
using namespace std;
// FANDA :     pop , ans , push 

void previousGreater(int arr[], int n, int pge[]) {
    stack<int> st;
    

    pge[0] = -1;
    st.push(arr[0]);

    for (int i = 1; i < n; i++)
    {

        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.empty())
            pge[i] = -1;
        else
            pge[i] = st.top();

        st.push(arr[i]);
    }
}

int main() {
    int arr[] = {3, 1, 2, 5, 4, 6, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pge[n]; // Result array to store Next Greater Elements

    // Call function
    previousGreater(arr, n, pge);

    // Print input
    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print output
    cout << "Previous Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << pge[i] << " ";
    }
    cout << endl;

    return 0;
}

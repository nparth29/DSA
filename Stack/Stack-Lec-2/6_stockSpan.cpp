#include<iostream>
#include<stack>
using namespace std;
// FANDA :     pop , ans , push 

void previousGreater(int arr[], int n, int pge[]) {
    stack<int> st;
    

    pge[0] = -1;
    st.push(0);

    for (int i = 1; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (st.empty())
            pge[i] = -1;
        else
            pge[i] = st.top();

        st.push(i);
    }
}

int main() {
    int arr[] = { 100, 80, 60, 81, 70, 60, 75, 85};
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
    cout << "Previous Greater indx: ";
    for (int i = 0; i < n; i++) {
        cout << pge[i] << " ";
    }
    cout << endl;

    int span[n];
    for (int i = 0; i < n;i++){
        span[i] = i - pge[i];
    }

    for (int i = 0; i < n;i++){
        cout << "Span of " << arr[i] << " is :" << span[i];
        cout << endl;
    }

        return 0;
}

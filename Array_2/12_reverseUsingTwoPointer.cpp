#include <iostream>
#include <vector>
#include <algorithm> // For reverse function
using namespace std;

void display(vector<int> &b) {
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int arr;
        cin >> arr;
        v.push_back(arr);
    }

    cout << "Original array: ";
    display(v);

    // Reversing using while loop
    int i = 0;
    int j = v.size() - 1;
    while (i <= j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    cout << "Using while loop: ";
    display(v);

    // Reversing using for loop
    for (int k = 0, l = v.size() - 1; k <= l; k++, l--) {
        int temp = v[k]; // Corrected this part
        v[k] = v[l];
        v[l] = temp;
    }
    cout << "Using for loop: ";
    display(v);

    // Reversing using built-in function
    cout << "Using built-in function: ";
    reverse(v.begin(), v.end());
    display(v);

    return 0;
}

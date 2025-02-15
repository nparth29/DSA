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

// Function to reverse a part of the vector
void reversePart(vector<int> &v, int i, int j) {
    // Boundary check for indices
    if (i < 0 || j >= v.size() || i > j) {
        cout << "Invalid indices for reversal." << endl;
        return;
    }

    while (i <= j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

int main() {
    vector<int> v;
    int n;

    // Input the vector size and elements
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int arr;
        cin >> arr;
        v.push_back(arr);
    }

    cout << "Original vector: ";
    display(v);

    // Reverse part of the vector
    int start, end;
    cout << "Enter the range to reverse (start and end indices): ";
    cin >> start >> end;

    reversePart(v, start, end);

    cout << "Vector after reversing the part: ";
    display(v);

    return 0;
}

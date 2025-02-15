#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    // Creating a reversed vector
    vector<int> b(v.size());
    for (int i = 0; i < n; i++) {
        b[i] = v[n - 1 - i];
    }


     cout << "Reversed array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Displaying the reversed vector
    cout << "input array: ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}

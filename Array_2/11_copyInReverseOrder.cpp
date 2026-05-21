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
        b[i] = v[n - 1 - i];    // i + j = n - 1 => j = n - 1 - i 
    }


     cout << "input array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Displaying the reversed vector
    cout << "reversed array: ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Sample Input: 1 2 3 4 5
Sample Output:5 4 3 2 1

we can see  
arr_input[0] = arr_output[4] 
arr_input[1] = arr_output[3]
arr_input[2] = arr_output[2]
arr_input[3] = arr_output[1]
arr_input[4] = arr_output[0]

form here we can say that arr_input[i] = arr_output[n-1-i] 
*/
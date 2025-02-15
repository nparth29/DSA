// #include<iostream>
// using namespace std;
// #include<vector>

// int main(){
//     int x;
//     cout << "enter the target value : ";
//     cin >> x;
 
//     vector<int> v;
//     int n;
//     cout << "enter the size of the array : ";
//     cin >> n;
//     cout << "enter array element : ";
//     for (int i = 0; i < n;i++){
//         int arr;
//         cin >> arr;
//         v.push_back(arr);
//     }


//     for (int i = 0; i <= v.size() - 2; i++)
//     {
//         for (int j = i + 1; j <= v.size() - 1; j++)
//         {
//             if (v[i] + v[j] == x)
//             {
//                 cout << "{" << i << "," << j << "}" << " ";
//             }
//         }
//     }
// }







#include <iostream>
#include <vector>
using namespace std;

int main() {
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Validation for array size
    if (n < 2) {
        cout << "The array must have at least 2 elements." << endl;
        return 1;
    }

    vector<int> v;
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    // Find pairs
    bool found = false;
    cout << "Pairs of indices whose elements sum to " << target << " are: ";
    for (int i = 0; i <= v.size() - 2; i++) {
        for (int j = i + 1; j <= v.size() - 1; j++) {
            if (v[i] + v[j] == target) {
                cout << "{" << i << ", " << j << "} ";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No pairs found." << endl;
    }

    return 0;
}

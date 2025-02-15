#include <iostream>
#include <vector>
#include <algorithm>  // for sorting
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    // Step 1: Sort both the greed array and the cookie size array
    sort(g.begin(), g.end());  // Sort the greed factors in ascending order
    sort(s.begin(), s.end());  // Sort the cookie sizes in ascending order

    int count = 0;  // Variable to keep track of the number of satisfied children
    int i = 0;  // Pointer for the children array (g)
    int j = 0;  // Pointer for the cookies array (s)

    // Step 2: Use the two-pointer technique to match cookies with children
    while (i < g.size() && j < s.size()) {  // Continue until all children or cookies are considered
        if (s[j] >= g[i]) {  // If the current cookie can satisfy the current child
            count++;  // Increment the count of satisfied children
            i++;  // Move to the next child
        }
        j++;  // Move to the next cookie (either way, we try the next cookie)
    }

    // Step 3: Return the number of satisfied children
    return count;
}

int main() {
    // Test case 1: Greed factors of children and sizes of cookies
    vector<int> g = {1, 2, 3};  // Children with greed factors
    vector<int> s = {1, 1};     // Cookies available

    // Call the function and print the result
    cout << "Max number of children that can be satisfied: " 
         << findContentChildren(g, s) << endl;  // Output should be 1

    // Test case 2: Another example with different greed and cookie sizes
    vector<int> g2 = {1, 2, 3, 4};
    vector<int> s2 = {3, 2, 1};

    // Call the function and print the result
    cout << "Max number of children that can be satisfied: " 
         << findContentChildren(g2, s2) << endl;  // Output should be 3

    return 0;
}

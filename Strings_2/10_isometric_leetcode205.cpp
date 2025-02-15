#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Function to check if two strings are isomorphic
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;  // Strings must have the same length

    vector<int> v(150, 1000);  // Size 150, initialized to 1000

    // Comparison of `t` with respect to `s`
    for (int i = 0; i < s.size(); i++) {
        int idx = (int)s[i];  // Find the index for character in `s`
        if (v[idx] == 1000)   // If not yet mapped
            v[idx] = s[i] - t[i];  // Store the difference of `s` and `t`
        else if (v[idx] != s[i] - t[i])  // Mismatch in mapping
            return false;
    }

    // Reinitialize `v` for the second comparison
    vector<int> v2(150, 1000);  // Create a new vector for the second pass

    // Comparison of `s` with respect to `t`
    for (int i = 0; i < s.size(); i++) {
        int idx = (int)t[i];  // Find the index for character in `t`
        if (v2[idx] == 1000)  // If not yet mapped
            v2[idx] = t[i] - s[i];  // Store the difference of `t` and `s`
        else if (v2[idx] != t[i] - s[i])  // Mismatch in mapping
            return false;
    }

    return true;  // Both comparisons passed
}

int main() {
    string s, t;

    // Input strings
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    // Check if the strings are isomorphic
    if (isIsomorphic(s, t)) {
        cout << "The strings are isomorphic.\n";
    } else {
        cout << "The strings are not isomorphic.\n";
    }

    return 0;
}

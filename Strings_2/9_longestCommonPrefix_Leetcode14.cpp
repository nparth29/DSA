#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// Function to find the longest common prefix among an array of strings
string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();    // Get the size of the input vector
        if(n == 1) return strs[0];  // If there's only one string, return it as the prefix

        sort(strs.begin(), strs.end());   // Sort the strings lexicographically

        string first = strs[0];          // First string after sorting
        string last = strs[n-1];         // Last string after sorting
        string s = "";                  // Initialize an empty string to store the prefix

        // Compare characters of the first and last strings until a mismatch or the shortest string ends
        for(int i = 0; i < min(first.size(), last.size()); i++) {
            if(first[i] == last[i]) {    // If characters match, add to the prefix
                s += first[i];
            } else {
                break;                   // Stop if characters mismatch
            }
        }
        return s;                        // Return the longest common prefix
}

int main() {
    vector<string> str;                 // Create a vector to hold the input strings

    // Populate the vector with strings
    str.push_back("flower");
    str.push_back("flow");
    str.push_back("flight");

    // Call the function to find the longest common prefix
    string s = longestCommonPrefix(str);

    // Print the result
    cout << "The longest common prefix is: " << s;
}

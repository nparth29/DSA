#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string s;
    cout << "Input string 's' : ";
    cin >> s; // Read the input string

    // Create a vector to store the frequency of each character (a-z)
    vector<int> arr(26, 0);

    // Iterate through the string to calculate the frequency of each character
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];           // Get the current character
        int ascii = (int)ch;      // Get the ASCII value of the character
        arr[ascii - 'a']++;       // Increment the frequency for the corresponding character
    }

    // Find the maximum frequency from the frequency array
    int max = 0;
    for (int i = 0; i < 26; i++) {
        if (max < arr[i])         // Update the max frequency if a larger frequency is found
            max = arr[i];
    }

    // Print all characters with the maximum frequency
    for (int i = 0; i < 26; i++) {
        if (arr[i] == max) {      // Check if the frequency matches the maximum frequency
            int ascii = i + 97;   // Convert the index back to the ASCII value for the character
            char ch = (char)ascii; // Convert ASCII value to the character
            cout << ch << " " << max << endl; // Print the character and its frequency
        }
    }

    return 0; // Indicate successful program execution
}

#include <iostream>
#include <string>
using namespace std;

// Method 1: Using an extra string to store the result
void removeChar(string str, string ans, char ch, int idx) {
    if (idx == str.length()) {
        cout << "Modified string (Method 1): " << ans << endl;
        return;
    }

    char ph = str[idx];
    if (str[idx] == ch) 
        removeChar(str, ans, ch, idx + 1);  // Skip the character
    else 
        removeChar(str, ans + ph, ch, idx + 1); // Keep the character
}

// Method 2: Returning a new modified string
string removeChar(string str, char ch, int idx = 0) {
    if (idx == str.length()) // Base case: if index reaches the end of string, return empty string
        return "";

    if (str[idx] == ch) 
        return removeChar(str, ch, idx + 1); // Skip the character and recurse for the next index

    return str[idx] + removeChar(str, ch, idx + 1); // Keep the character and recurse
}

int main() {
    string str;
    char ch;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Enter the character to remove: ";
    cin >> ch;

    // Calling both methods
    removeChar(str, "", ch, 0); // Method 1
    cout << "Modified string (Method 2): " << removeChar(str, ch) << endl; // Method 2

    return 0;
}

/*
dry run of method 2: 

removeChar("banana", 'a', 0)  // idx = 0, str[0] = 'b'
      |
'b' + removeChar("banana", 'a', 1)  // idx = 1, str[1] = 'a' (skip)
      |
      |---removeChar("banana", 'a', 2)  // idx = 2, str[2] = 'n'
      |       |
      |       'n' + removeChar("banana", 'a', 3)  // idx = 3, str[3] = 'a' (skip)
      |       |
      |       |---removeChar("banana", 'a', 4)  // idx = 4, str[4] = 'n'
      |       |       |
      |       |       'n' + removeChar("banana", 'a', 5)  // idx = 5, str[5] = 'a' (skip)
      |       |       |
      |       |       |---removeChar("banana", 'a', 6)  // idx = 6 (base case)
      |       |       |       |
      |       |       |       ""  // Return ""
      |       |       |       |
      |       |       "n" // Return "n" + "" = "n"
      |       |       |
      |       |       "nn" // Return "n" + "n" = "nn"
      |       |
      |       "nn" // Return "n" + "nn" = "nn"
      |
      "bnn" // Return "b" + "nn" = "bnn"
      |
"bnn" //Final Result

*/
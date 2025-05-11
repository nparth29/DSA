#include <iostream>
#include <string>
using namespace std;

// Method 1: Using an extra string to store the result
void printSubset(string str, string ans) {
    if (str == "") {
        cout << ans << endl;
        return;
    }
    char ph = str[0];
    printSubset(str.substr(1), ans);  // Skip the character
    printSubset(str.substr(1), ans + ph); // Keep the character
}



int main() {
    string str;
    char ch;
    cout << "Enter a string: ";
    cin >> str;


    printSubset(str, ""); // Method 1
    return 0;
}
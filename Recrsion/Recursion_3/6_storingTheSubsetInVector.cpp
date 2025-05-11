#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSubset(string &str, string ans, vector<string> &v, int idx) {
    if (idx == str.length()) {
        v.push_back(ans);
        return;
    }
    // Exclude the current character
    printSubset(str, ans, v, idx + 1);
    // Include the current character
    printSubset(str, ans + str[idx], v, idx + 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    vector<string> v;

    printSubset(str, "", v, 0); // Start from index 0
    for (string elem : v) {
        cout << elem << endl;
    }
    return 0;
}
/*

Dry Run with Line Numbers and Execution Flow (str = "ab"):

main (Line 23): Calls printSubset("ab", "", {}, 0).

printSubset("ab", "", {}, 0):

Line 7: idx (0) != str.length() (2).
Line 12: Calls printSubset("ab", "", {}, 1).
printSubset("ab", "", {}, 1):

Line 7: idx (1) != str.length() (2).
Line 12: Calls printSubset("ab", "", {}, 2).
printSubset("ab", "", {}, 2):

Line 7: idx (2) == str.length() (2).
Line 8: v.push_back(""). v is now {"", }.
Line 9: return; (Returns to Line 12 of the caller).
printSubset("ab", "", {}, 1) (Resumes):

Line 14: Calls printSubset("ab", "b", {}, 2).
printSubset("ab", "b", {}, 2):

Line 7: idx (2) == str.length() (2).
Line 8: v.push_back("b"). v is now {"", "b"}.
Line 9: return; (Returns to Line 14 of the caller).
printSubset("ab", "", {}, 1) (Resumes):

Line 15: (Implicit return as function ends). Returns to Line 12 of the call where it was called from.
printSubset("ab", "", {}, 0) (Resumes):

Line 14: Calls printSubset("ab", "a", {}, 1).
printSubset("ab", "a", {}, 1):

Line 7: idx (1) != str.length() (2).
Line 12: Calls printSubset("ab", "a", {}, 2).
printSubset("ab", "a", {}, 2):

Line 7: idx (2) == str.length() (2).
Line 8: v.push_back("a"). v is now {"", "b", "a"}.
Line 9: return;
printSubset("ab", "a", {}, 1) (Resumes):

Line 14: Calls printSubset("ab", "ab", {}, 2).
printSubset("ab", "ab", {}, 2):

Line 7: idx (2) == str.length() (2).
Line 8: v.push_back("ab"). v is now {"", "b", "a", "ab"}.
Line 9: return;
printSubset("ab", "a", {}, 1) (Resumes):

Line 15: (Implicit return). Returns to Line 14 of the call where it was called from.
printSubset("ab", "", {}, 0) (Resumes):

Line 15: (Implicit return). Returns to Line 23 of main.
main (Line 25): Prints the elements of v: "", "b", "a", "ab".



*/
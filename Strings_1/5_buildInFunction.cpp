#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "my name is Naman Mishra";

    // Size and Length
    cout << "String: " << str << endl;
    cout << "Size (excluding null character): " << str.size() << endl; // Excludes the null character
    cout << "Length: " << str.length() << endl; // Equivalent to size()

    // push_back() and pop_back()
    string str2 = "abcd";
    cout << "\nInitial string: " << str2 << endl;

    str2.push_back('e');  // Append a single character
    cout << "After push_back('e'): " << str2 << endl;

    str2.push_back('f');  // Append another character
    cout << "After push_back('f'): " << str2 << endl;

    str2.pop_back();  // Remove the last character
    cout << "After pop_back(): " << str2 << endl;

    // Concatenation using +
    string s = "abc";
    string t = "def";
    s = s + t;  // Append string `t` to `s`
    cout << "\nAfter concatenation s + t: " << s << endl;

    s = "PYQ" + s;  // Prepend "PYQ" to `s`
    cout << "After prepending 'PYQ': " << s << endl;

    // Reverse the string
    reverse(s.begin(), s.end());
    cout << "After reversing: " << s << endl;

    // reverse(str4.begin()+1, str4.end()-1);  // index 1 to 3 get reversed
    // cout << str4 << endl;

    return 0;
}




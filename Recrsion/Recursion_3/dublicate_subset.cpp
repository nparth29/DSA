

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printSubset(string str, string ans, bool flag, vector<string> &v) {
    if (str.empty()) {
        v.push_back(ans);
        return;
    }

    char ch = str[0];

    if (str.length() == 1) {
        if (flag) printSubset(str.substr(1), ans + ch, true, v);
        printSubset(str.substr(1), ans, true, v);
        return;
    }

    char ph = str[1];
    if (ch == ph) {
        if (flag) printSubset(str.substr(1), ans + ch, true, v);
        printSubset(str.substr(1), ans, false, v);
    } else {
        if (flag) printSubset(str.substr(1), ans + ch, true, v);  // ✅ Fix applied
        printSubset(str.substr(1), ans, true, v);  
    }
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    vector<string> v;

    sort(str.begin(), str.end());
    printSubset(str, "", true, v);

    for (const string &s : v) {
        cout << s << endl;
    }

    return 0;
}

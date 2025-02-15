#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the string: ";
    cin >> n;

    // Clear the input buffer to ensure getline works correctly after cin
    cin.ignore();

    string name;
    cout << "Enter the string: ";
    getline(cin, name); // Read the string

    if (name.length() > n) {
        cout << "Warning: The entered string is longer than the specified size.\n";
    } else if (name.length() < n) {
        cout << "Warning: The entered string is shorter than the specified size.\n";
    }

    cout << "The string is: " << name << endl;

    return 0;
}

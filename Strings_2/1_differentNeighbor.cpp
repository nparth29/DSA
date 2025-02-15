#include <iostream>
#include <string>
using namespace std;

int countDifferentNeighbors(const string& input) {
    if (input.empty()) {
        return 0;
    }

    int count = 0;
    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] != input[i - 1]) {
            ++count;
        }
    }
    return count;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = countDifferentNeighbors(input);
    cout << "The number of times neighboring characters are different: " << result << endl;

    return 0;
}

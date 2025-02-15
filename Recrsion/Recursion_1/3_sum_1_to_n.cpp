#include <iostream>
using namespace std;

void sumParamaterised(int sum, int n) {
    if (n == 0) {
        cout << sum; // Print final sum
        return;  // Stop further recursion
    }
    sum = sum + n;
    sumParamaterised(sum, n - 1);  // Recursive call
}

int sum(int n) {
    if (n == 0)
        return 0;
    return n + sum(n - 1);  // Just like factorial
}

int main() {
    int n = 6;
    sumParamaterised(0, n); // Expected output: 21
    int sol = sum(5);
    cout << endl
         << sol; // Expected output: 15
}

#include <iostream>
using namespace std;

int countWays(int n) {
    if (n == 1) return 1; // for 1 step
    if (n == 2) return 2;  // for 2 step

    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Total ways to reach the top: " << countWays(n);
    return 0;
}

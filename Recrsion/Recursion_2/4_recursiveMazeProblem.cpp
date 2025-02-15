#include <iostream>
using namespace std;

int countPaths(int m, int n) {
    if (m == 1 || n == 1)  // If we reach the last row or last column, only 1 way left
        return 1;
    
    return countPaths(m - 1, n) + countPaths(m, n - 1);
}

void printPath(int m, int n, string s) {
    if (m == 1 && n == 1) {  // Reached the bottom-right corner
        cout << s << endl;  // Print the path
        return;
    }
    
    if (m > 1)  // Move Down (D) only if within bounds
        printPath(m - 1, n, s + "D");
    
    if (n > 1)  // Move Right (R) only if within bounds
        printPath(m, n - 1, s + "R");
}

int main() {
    int m, n;
    cout << "Enter maze dimensions (rows and columns): ";
    cin >> m >> n;

    cout << "Total paths in a " << m << "x" << n << " maze: " << countPaths(m, n) << endl;
    cout << "Paths are:\n";
    printPath(m, n, "");
    
    return 0;
}


/*
Why m > 1 for Moving Down (D)?
The function printPath(m - 1, n, s + "D") is moving downward.
If m == 1, moving down would exceed the bottom boundary (i.e., m-1 would become 0, which is invalid).
So, we only allow downward moves if m > 1.
Example:
For a 3×3 maze, if we are at (1,3), we cannot move downward because we are already in the last row.

Why n > 1 for Moving Right (R)?
The function printPath(m, n - 1, s + "R") is moving right.
If n == 1, moving right would exceed the right boundary (i.e., n-1 would become 0, which is invalid).
So, we only allow rightward moves if n > 1.
Example:
For a 3×3 maze, if we are at (3,1), we cannot move right because we are already in the last column.

*/
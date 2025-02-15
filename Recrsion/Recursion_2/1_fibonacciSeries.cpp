#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 1 || n == 2) return 1; // Base cases: Fibonacci(1) = 1, Fibonacci(2) = 1

    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n;
    
    // Taking user input
    cout << "Enter the number of terms: ";
    cin >> n;

    // Printing Fibonacci series
    cout << "Fibonacci series: ";
    if(n == 0){
        cout << 0;
        return 0;
    }
        
    for (int i = 1; i <= n; i++) {  // Start loop from 1
        cout << fibonacci(i) << " ";
    }

    return 0;
}

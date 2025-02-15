#include<iostream>
using namespace std;

// Function to find the first and last digits of a number
void find(int n, int* ptr1, int* ptr2) {
    *ptr2 = n % 10;  // Get the last digit
    while (n >= 10) { // Loop to find the first digit
        n = n / 10;
    }
    *ptr1 = n; // Assign the first digit
}

int main() {
    int n;
    cout << "Enter the value: ";
    cin >> n;

    int first_digit, last_digit;

    // Find the first and last digits of the number
    find(n, &first_digit, &last_digit);

    cout << "First digit: " << first_digit << " Last digit: " << last_digit << endl;

    return 0;
}
#include <iostream>
using namespace std;

int power(int num, int pow) { 
    if (num == 0 && pow == 0) {
        return -1; // Indeterminate form
    } 
    else if (pow == 0) {
        return 1;
    }
    
    return num * power(num, pow - 1);
}

int main() {
    int num, pow;
    
    // Taking input from user
    cout << "Enter base number: ";
    cin >> num;
    cout << "Enter exponent (power): ";
    cin >> pow;

    int ans = power(num, pow);

    if (ans == -1) {
        cout << "Indeterminate form (0^0)";
    } else {
        cout << num << "^" << pow << " = " << ans;
    }

    return 0;
}

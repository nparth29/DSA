#include <iostream>
using namespace std;

int power(int num, int pow) {
    if (pow == 0) return 1; // Base case: num^0 = 1
    
    int halfPower = power(num, pow / 2); // Recursive call for pow/2

    if (pow % 2 == 0)
        return halfPower * halfPower; // If even: num^pow = (num^(pow/2))^2
    else
        return num * halfPower * halfPower; // If odd: num^pow = num * (num^(pow/2))^2
}

int main() {
    int num, pow;
    
    cout << "Enter base number: ";
    cin >> num;
    cout << "Enter exponent (power): ";
    cin >> pow;

    cout << num << "^" << pow << " = " << power(num, pow);

    return 0;
}

#include <iostream>
using namespace std;

class MathOperations {
public:
    // Function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded function: adds three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Overloaded function: adds two floating-point numbers
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    MathOperations math;

    cout << "Sum of 5 and 10: " << math.add(5, 10) << endl;            // Calls int add(int, int)
    cout << "Sum of 5, 10 and 15: " << math.add(5, 10, 15) << endl;    // Calls int add(int, int, int)
    cout << "Sum of 5.5 and 2.5: " << math.add(5.5, 2.5) << endl;      // Calls double add(double, double)

    return 0;
}

#include <iostream>
using namespace std;

class Bike {
private:
    string brand;
    int engineCapacity;

public:
    // **Default Constructor (No Parameters)**
    Bike() {
        brand = "Unknown";
        engineCapacity = 0;
        cout << "Default Constructor: Bike Created with Unknown Brand" << endl;
    }

    // **Parameterized Constructor (1 Parameter)**
    Bike(string b) {
        brand = b;
        engineCapacity = 0;  // Default engine capacity
        cout << "One-Argument Constructor: Bike Created - " << brand << endl;
    }

    // **Parameterized Constructor (2 Parameters)**
    Bike(string b, int capacity) {
        brand = b;
        engineCapacity = capacity;
        cout << "Two-Argument Constructor: Bike Created - " << brand << " with " << engineCapacity << "cc" << endl;
    }

    // Display Function
    void display() {
        cout << "Brand: " << brand << ", Engine Capacity: " << engineCapacity << " cc" << endl;
    }
};

int main() {
    Bike b1;                 // Calls Default Constructor
    Bike b2("Yamaha");       // Calls 1-Parameter Constructor
    Bike b3("Honda", `180);   // Calls 2-Parameter Constructor

    cout << "\nBike Details:" << endl;
    b1.display();
    b2.display();
    b3.display();

    return 0;
}

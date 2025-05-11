#include <iostream>
using namespace std;

class Bike {
private:
    string brand;       // Non-static variable (each object has its own brand)
    int engineCapacity; // Non-static variable (each object has its own engineCapacity)
    
public:
    static int totalBikes;  // Static variable (shared among all objects)

    // Constructor (Non-static function)
    Bike(string brand, int capacity) {
        this->brand = brand;
        this->engineCapacity = capacity;
        totalBikes++;  // Increment the static variable
        cout << "Bike Created: " << brand << " with " << engineCapacity << "cc" << endl;
    }

    // **Non-static function (works on object-specific data)**
    void displayBikeInfo() {
        cout << "Brand: " << brand << ", Engine Capacity: " << engineCapacity << " cc" << endl;
    }

    // **Static function (can only access static variables)**
    static void displayTotalBikes() {
        cout << "Total bikes created: " << totalBikes << endl;
    }

    // Destructor (Non-static function)
    ~Bike() {
        cout << "Destructor called for: " << brand << endl;
    }
};

// **Initializing static variable outside the class**
int Bike::totalBikes = 0;

int main() {
    cout << "Initially, Total Bikes: ";
    Bike::displayTotalBikes();  // Calling static function using class name

    cout << "\nCreating Bikes...\n";
    Bike b1("Yamaha", 200);
    Bike b2("Honda", 180);
    
    cout << "\nDisplaying Individual Bike Info:\n";
    b1.displayBikeInfo();  // Calling non-static function
    b2.displayBikeInfo();  // Calling non-static function

    cout << "\nUpdating Total Bikes:\n";
    Bike::displayTotalBikes();  // Calling static function

    cout << "\nCreating another Bike...\n";
    Bike b3("Suzuki", 150);
    
    cout << "\nFinal Total Bikes:\n";
    Bike::displayTotalBikes();  // Calling static function
    
    return 0;  
}

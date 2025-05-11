#include <iostream>
using namespace std;

class Bike {
private:
    string brand;
    int* engineCapacity;  // Pointer to dynamically allocated memory

public:
    // Constructor
    Bike(string brand, int capacity) {
        this->brand = brand;
        engineCapacity = new int(capacity);  // Dynamic allocation
        cout << "Bike object created: " << brand << " with " << *engineCapacity << "cc" << endl;
    }

    // **Copy Constructor (Deep Copy)**
    Bike(const Bike& other) {
        brand = other.brand;  // Copy brand
        engineCapacity = new int(*other.engineCapacity);  // Allocate new memory and copy value
        cout << "Copy Constructor called! Deep copy created for: " << brand << endl;
    }

    // **Setter for Engine Capacity**
    void setEngineCapacity(int capacity) {
        *engineCapacity = capacity;
    }

    // **Getter for Engine Capacity**
    int getEngineCapacity() const {
        return *engineCapacity;
    }

    // Display function
    void display() {
        cout << "Brand: " << brand << ", Engine Capacity: " << *engineCapacity << " cc" << endl;
    }

    // Destructor
    ~Bike() {
        delete engineCapacity;  // Free allocated memory
        cout << "Destructor called for: " << brand << endl;
    }
};

int main() {
    Bike bike1("Yamaha", 200);  // Original object
    Bike bike2 = bike1;         // Copy constructor is called

    cout << "\nOriginal Object (bike1): ";
    bike1.display();

    cout << "Copied Object (bike2): ";
    bike2.display();

    // Modify copied object using the setter function
    cout << "\nModifying bike2's engine capacity...\n";
    bike2.setEngineCapacity(250);  // ✅ Correct way to modify a private variable

    cout << "\nAfter Modification:" << endl;
    cout << "Original Object (bike1): ";
    bike1.display();  // Should remain 200cc
    cout << "Copied Object (bike2): ";
    bike2.display();  // Should be updated to 250cc

    return 0;
}

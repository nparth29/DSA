#include <iostream>
using namespace std;

class Bike {
private:
    string brand;
    int tyresize;
    string color;
    int engineCapacity;

public:
    // Default Constructor with Default Parameters
    Bike(string brand = "Unknown", int tyresize = 17, string color = "Black", int engineCapacity = 150) {
        this->brand = brand;
        this->tyresize = tyresize;
        this->color = color;
        this->engineCapacity = engineCapacity;

        cout << "Bike object created successfully!" << endl;
    }

    // Getter methods
    string getBrand() { return brand; }
    int getTyreSize() { return tyresize; }
    string getColor() { return color; }
    int getEngineCapacity() { return engineCapacity; }

    // Setter methods
    void setBrand(string brand) { this->brand = brand; }
    void setTyreSize(int tyresize) { this->tyresize = tyresize; }
    void setColor(string color) { this->color = color; }
    void setEngineCapacity(int engineCapacity) { this->engineCapacity = engineCapacity; }

    // Display function to show bike details
    void displayBikeInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Tyre Size: " << tyresize << " inches" << endl;
        cout << "Color: " << color << endl;
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
    }
};

int main() {
    // Creating object using default constructor
    Bike defaultBike;
    defaultBike.displayBikeInfo();

    cout << endl;

    // Creating object with customized values
    Bike customBike("Yamaha", 19, "Red", 200);
    customBike.displayBikeInfo();

    cout << endl;

    // Modifying object using setters
    customBike.setBrand("Honda");
    customBike.setTyreSize(18);
    customBike.setColor("Blue");
    customBike.setEngineCapacity(180);

    cout << "After Modification:" << endl;
    customBike.displayBikeInfo();

    return 0;
}

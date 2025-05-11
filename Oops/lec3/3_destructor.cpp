// Role of Destructor in C++
// A destructor is a special member function of a class that is automatically called when an object goes out of scope (i.e., is destroyed). It helps in:

//  Releasing resources (e.g., memory, file handles, network connections).
//  Cleaning up dynamically allocated memory (if used).
//   Performing final actions before an object is removed from memory.

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
    Bike(string brand = "Unknown", int tyresize = 17, string color = "Black", 
                                                    int engineCapacity = 150) {
        this->brand = brand;
        this->tyresize = tyresize;
        this->color = color;
        this->engineCapacity = engineCapacity;

        cout << "Bike object created successfully: " << brand << endl;
    }

    // Destructor
    ~Bike() {
        cout << "Destructor called! Bike object destroyed: " << brand << endl;
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
    cout << "Creating defaultBike..." << endl;
    Bike defaultBike;
    defaultBike.displayBikeInfo();

    cout << endl;

    // Creating object with customized values
    cout << "Creating customBike..." << endl;
    Bike customBike("Yamaha", 19, "Red", 200);
    customBike.displayBikeInfo();

    cout << endl;
    bool flag = true;
    if(flag == true){
        Bike Discover("discover", 20, "Purpel", 250);
        Discover.displayBikeInfo();
    }
    cout << endl;

    // Modifying object using setters
    cout << "Modifying customBike..." << endl;
    customBike.setBrand("Honda");
    customBike.setTyreSize(18);
    customBike.setColor("Blue");
    customBike.setEngineCapacity(180);

    cout << "After Modification:" << endl;
    customBike.displayBikeInfo();

    cout << "End of main function, objects will now be destroyed..." << endl;

    return 0;
}

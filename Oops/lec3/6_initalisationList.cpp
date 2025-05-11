#include <iostream>
using namespace std;

class Engine {
public:
    Engine(int power) {
        cout << "Engine Created with Power: " << power << "cc" << endl;
    }
};

class Bike {
private:
    Engine engine;  // `Engine` object must be initialized
    string brand;

public:
    // Initialization list required for `engine`
    Bike(string b, int power) : engine(power), brand(b) {
        cout << "Bike Created: " << brand << endl;
    }
};

int main() {
    Bike b1("Ducati", 1000);
    return 0;
}

#include <iostream>
using namespace std;

class Bike {
public:  // Constructor should be in the public section
    // Default constructor
    Bike() {
        cout << "Constructor call hua!!"<<endl;
    }
};

int main() {
    Bike tvs;  // Creating an object
    Bike honda;
    return 0;
}

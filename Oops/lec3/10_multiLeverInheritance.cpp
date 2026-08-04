#include <iostream>
using namespace std;

// **Base Class: Grandparent**
class Grandparent {
private:
    int gp_private = 10;  // ❌ Not inherited

protected:
    int gp_protected = 20;  // ✅ Inherited but remains protected

public:
    Grandparent()
    {
        cout << "Grandparent Constructor called" << endl;
}

public:
    int gp_public = 30;  // ✅ Inherited & accessible in public inheritance

    void showGrandparent() {
        cout << "Grandparent -> Private: " << gp_private << " (Not Inherited)\n";
        cout << "Grandparent -> Protected: " << gp_protected << " (Inherited but access varies)\n";
        cout << "Grandparent -> Public: " << gp_public << " (Inherited & Accessed)\n";
    }
};

// **Derived Class: Parent (Inherits from Grandparent)**
class Parent : public Grandparent {
public:
    Parent(){
        cout << "Parent Constructor called" << endl;
    }


    int parent_public = 40;

    void showParent() {
        // cout << gp_private; ❌ Not accessible (private members not inherited)
        cout << "Grandparent's Protected in Parent: " << gp_protected << " (Accessible as Protected)\n";
        cout << "Grandparent's Public in Parent: " << gp_public << " (Accessible as Public)\n";
        cout << "Parent's Own Public: " << parent_public << endl;
    }
};

// **Derived Class: Child (Inherits from Parent)**
class Child : public Parent {
public:
    int child_public = 50;

    Child(){
        cout << "Child Constructor called" << endl;
    }

    void showChild() {
        // cout << gp_private; ❌ Not accessible (private members not inherited)
        cout << "Grandparent's Protected in Child: " << gp_protected << " (Accessible as Protected)\n";
        cout << "Grandparent's Public in Child: " << gp_public << " (Accessible as Public)\n";
        cout << "Parent's Public in Child: " << parent_public << " (Accessible as Public)\n";
        cout << "Child's Own Public: " << child_public << endl;
    }
};

int main() {
    cout << "=== Grandparent Class ===\n";
    Grandparent gp;
    gp.showGrandparent();
    cout << endl;

    cout << "=== Parent Class (Inherited from Grandparent) ===\n";
    Parent p;
    p.showParent();
    cout << "Parent can access Grandparent's public: " << p.gp_public << endl;  // ✅ Allowed
    cout << endl;

    cout << "=== Child Class (Inherited from Parent) ===\n";
    Child c;
    c.showChild();
    cout << "Child can access Grandparent's public: " << c.gp_public << endl;  // ✅ Allowed
    cout << "Child can access Parent's public: " << c.parent_public << endl;  // ✅ Allowed
    cout << endl;

    return 0;
}

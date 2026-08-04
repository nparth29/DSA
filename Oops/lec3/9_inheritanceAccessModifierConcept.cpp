 #include <iostream>
using namespace std;

// **Base Class A**
class A {
private:
    int a_private = 10;  // ❌ Not inherited (Completely hidden)

protected:
    int a_protected = 20;  // ✅ Inherited but remains protected (unless changed)

public:
    int a_public = 30;  // ✅ Inherited & accessible in Public Inheritance

    void showA() {
        cout << "Base A -> Private: " << a_private << " (Not Inherited)\n";
        cout << "Base A -> Protected: " << a_protected << " (Inherited but access varies)\n";
        cout << "Base A -> Public: " << a_public << " (Inherited & Accessed)\n";
    }
};

// **Derived Class B (Publicly Inheriting A)**
class B : public A {
public:
    int b_public = 40;

    void showB() {
        // cout << "Private of A: " << a_private << endl; ❌ Not accessible (private members not inherited)
        cout << "Protected of A in B: " << a_protected << " (Accessible as Protected)\n";
        cout << "Public of A in B: " << a_public << " (Accessible as Public)\n";
    }
};

// **Derived Class C (Protectedly Inheriting A)**
class C : protected A {
public:
    int c_public = 50;

    void showC() {
        // cout << "Private of A: " << a_private << endl; ❌ Not accessible (private members not inherited)
        cout << "Protected of A in C: " << a_protected << " (Still Protected)\n";
        cout << "Public of A in C: " << a_public << " (Converted to Protected)\n";
    }
};

// **Derived Class D (Privately Inheriting A)**
class D : private A {
public:
    int d_public = 60;

    void showD() {
        // cout << "Private of A: " << a_private << endl; ❌ Not accessible (private members not inherited)
        cout << "Protected of A in D: " << a_protected << " (Converted to Private)\n";
        cout << "Public of A in D: " << a_public << " (Converted to Private)\n";
    }
};

int main() {
    cout << "=== Base Class A ===\n";
    A objA;
    objA.showA();
    cout << endl;

    cout << "=== Public Inheritance (B : public A) ===\n";
    B objB;
    objB.showB();
    cout << "B can access A's public: " << objB.a_public << endl;  // ✅ Allowed
    // cout << objB.a_protected; ❌ Not accessible outside the class
    cout << endl;

    cout << "=== Protected Inheritance (C : protected A) ===\n";
    C objC;
    objC.showC();
    // cout << objC.a_public; ❌ Not accessible (Converted to Protected)
    cout << endl;

    cout << "=== Private Inheritance (D : private A) ===\n";
    D objD;
    objD.showD();
    // cout << objD.a_public; ❌ Not accessible (Converted to Private)
    cout << endl;

    return 0;
}

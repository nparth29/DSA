#include<iostream>
#include<set>
using namespace std;

int main(){
    // Ordered Set
    set<int> orderedSet;

    // Inserting elements
    orderedSet.insert(5);
    orderedSet.insert(1);
    orderedSet.insert(3);
    orderedSet.insert(2);
    orderedSet.insert(4);

    // output will be in sorted form ( just like in mathematics)
    cout << "Ordered Set elements (in ascending order): ";
    for(auto &elem : orderedSet){
        cout << elem << " ";
    }
    cout << endl;

    // Checking existence of an element
    int toFind = 3;
    if(orderedSet.find(toFind) != orderedSet.end()){
        cout << toFind << " is present in the set." << endl;
    } else {
        cout << toFind << " is not present in the set." << endl;
    }

    // Removing an element
    orderedSet.erase(2);
    cout << "After removing 2, Ordered Set elements: ";
    for(const int &elem : orderedSet){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}


// note: insertion and deletion take O(log n) time in ordered set
// because it is implemented using balanced BST (like Red-Black Tree).
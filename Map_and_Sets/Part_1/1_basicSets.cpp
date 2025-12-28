#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;

    // Inserting elements
    s.insert(10);
    s.insert(20);
    s.insert(30);

    cout << "size of set: " << s.size() << endl;
    cout << "Elements in the set: ";
    for(const int &elem : s){  // we can also use auto instead of int
        cout << elem << " ";
    }
    cout << endl;
    // even we add repeated elements, it will store only unique elements
    s.insert(20);
    cout<<"size of set after inserting duplicate element: "<<s.size()<<endl;
    cout << "After inserting duplicate element 20, elements in the set: ";
    for (const int &elem : s){
        cout << elem << " ";
    }

    // // Checking existence
    int key = 20;
    // s.find() -> it searches the element in the set, and if not found then it returns the last element (s.end())
    if(s.find(key) != s.end()){ // if the key is not equal to s.end() that means the element is present in the set
        cout << "\n" <<key<< " is present in the set."<<endl;
    }
    else{
        cout << "\n" <<key<< "is not present in the set."<<endl;
    }
    return 0;
}
#include<iostream>
#include<map>
using namespace std; 

int main(){
    map<int, int> m;

    // inserting 
    m[3] = 13;
    m[1] = 10;
    m[4] = 15;
    m[2] = 9;

    // printing 
    for( auto elem : m){
        cout << elem.first << " -> " << elem.second << endl;
    }

    // lets try to pring only secnod element and see the printing behavior
    cout << "Accessing elements using keys:" << endl;
    for(auto elem: m){
        cout << "value " << elem.second << endl; //    // we conclude that the map is sorted according to keys(high priority)

    }

    // lets take string and vlaues 
    map<string, int> strMap;
    strMap["Raghav"] = 10;
    strMap["Anjali"] = 20;
    strMap["Mona"] = 15;   

    // printing happens bassed on lexographical order of keys
    cout << "String Map elements:" << endl;
    for(auto elem: strMap){
        cout << elem.first << " -> " << elem.second << endl;
    }

}
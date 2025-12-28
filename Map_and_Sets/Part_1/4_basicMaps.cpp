#include<iostream>
#include<unordered_map>
using namespace std;

void method1(){
    unordered_map<string, int> m;
    // inserting key-value pairs
    pair<string, int> p1;
    p1.first = "apple";
    p1.second = 100;
    m.insert(p1);

    pair<string, int> p2;
    p2.first = "banana";
    p2.second = 150;
    m.insert(p2);

    pair<string, int> p3;
    p3.first = "orange";
    p3.second = 200;
    m.insert(p3);

    // display 
    for(auto &pr : m){
        cout<<pr.first<<" : "<<pr.second<<endl;
    }
}

void method2(){
    unordered_map<string, int> m;
    // inserting key-value pairs
    m["Raghav"] = 100;
    m["Parth"] = 150;
    m["Shiva"] = 200;
    m["Ankit"] = 250;

    // display 
    for(auto &pr : m){
        cout<<pr.first<<" : "<<pr.second<<endl;
    }
    cout<<"Size of map: "<<m.size()<<endl;

    // removing a key-value pair
    m.erase("Shiva");
    cout<<"Size of map after erasing Shiva: "<<m.size()<<endl;
    // if we try to erase a key which is not present in the map, then nothing happens (no error is thrown)
    m.erase("NonExistingKey");
    cout<<"Size of map after trying to erase NonExistingKey: "<<m.size()<<endl;

    // searching for a key
    string key = "Raghav";
    if(m.find(key) != m.end()){
        cout<<key<<" is present in the map with value "<<m[key]<<endl;
    }
    else{
        cout<<key<<" is not present in the map"<<endl;
    }
}   

int main(){
    method1();
    cout<< "-------------------"<<endl;
    method2();
    return 0;
}
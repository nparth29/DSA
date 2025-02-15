#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>  //  for sort 

int main(){
    vector<int> v;  // you need not to mention the size of the vector
    // inserting and input, do not use []
    // v[0]; wrong 
    v.push_back(6);
    v.push_back(19);
    v.push_back(1);
    v.push_back(12);
    v.push_back(9);
    v.push_back(17);
    v.push_back(10);

    for (int i = 0; i < v.size();i++){
        cout << " " << v[i];
    }
    cout << endl;
    v.at(2) = 90;
    for (int i = 0; i < v.size();i++){
        cout << " " << v[i];
    }
    cout << endl;

    // sort
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size();i++){
        cout << " " << v[i];
    }

}
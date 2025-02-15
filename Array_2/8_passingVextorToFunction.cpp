#include<iostream>
using namespace std;
#include<vector>
            // vector are pass by value 
// void change(vector<int> v){
//     v.push_back(6);
//     v[0] = 11;

//     for (int i = 0; i < v.size();i++){
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

void change(vector<int>& v){    // we use & for "reference"
    v.push_back(6);
    v[0] = 11;

    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(6);
    v.push_back(1);
    v.push_back(5);

    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    change(v);
    cout << endl;

    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
}

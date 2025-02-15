#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int> v(5);
    cout <<endl<<"size: "<< v.size() << " " <<"capicity :"<< v.capacity() << endl;
    for (int i = 0; i < v.size();i++){
        cout << " " << v[i];
    }


    vector<int> r(5,7);  // r(size, element value)
    cout <<endl<<"size: "<< r.size() << " " <<"capicity :"<< r.capacity() << endl;
    for (int i = 0; i < r.size();i++){
        cout << " " << r[i];
    }
}
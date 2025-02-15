#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> v;  // you need not to mention the size of the vector
    // inserting and input, do not use []
    // v[0]; wrong 
    v.push_back(6);
    cout <<"size: "<< v.size() << " " <<"capicity :"<< v.capacity() << endl;
    v.push_back(1);
    cout <<"size: "<< v.size() << " " <<"capicity :"<< v.capacity() << endl;
    v.push_back(9);
    cout <<"size: "<< v.size() << " " <<"capicity :"<< v.capacity() << endl;
    v.push_back(10);
    cout <<"size: "<< v.size() << " " <<"capicity :"<< v.capacity() << endl;


// we can use square braclet [] to update or print the vectors 
    cout << v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3] <<endl;
    
}
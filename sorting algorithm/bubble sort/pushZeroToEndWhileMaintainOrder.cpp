// Push all the zeroes to end of array while maintaining the order of non-zero elements
// input : {5,0,1,2,0,0,4,0,3} --> output : {5,1,2,4,3,0,0,0,0}
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {5,0,1,2,0,0,4,0,3};
    int n = v.size();

    for (int i = 0; i < n - 1;i++){
        for (int j = 0; j < n - 1 - i;j++){
            if(v[j]==0){
                swap(v[j], v[j + 1]);
            }
        }
    }

    for (int i = 0; i < n;i++){
        cout<<v[i]<<" ";
    }
}
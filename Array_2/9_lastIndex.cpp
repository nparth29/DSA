// Looping in vector
//Que: find the last occurrence of x in the array

#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(6);
    v.push_back(1);
    v.push_back(5);
    v.push_back(78);
    v.push_back(10);
    v.push_back(6);
    v.push_back(1);
    v.push_back(9);

    int x = 9;
    int index = -1;
// method 1 : forward loop

//     for (int i = 0; i < v.size();i++){
//         if (v[i] == x)
//             index = i;
//     }
//     cout << index;
// }

// method 2 : backward loop
    for (int i = v.size()-1; i >= 0;i--){
        if(v[i]==x){
            index = i;
            break;
        }
        
    }
    cout << index;
}
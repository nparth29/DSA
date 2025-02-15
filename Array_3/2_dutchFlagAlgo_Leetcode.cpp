#include<iostream>
using namespace std;
#include<vector>

void display(vector<int> &v){
    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void dutchFlagALgo(vector<int>&v){
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;
    while(mid<=high){
    if(v[mid]==2){
        int temp = v[mid];
        v[mid] = v[high];
        v[high] = temp;
        high--;
    }
    else if(v[mid]==0){
        int temp = v[mid];
        v[mid] = v[low];
        v[low] = temp;
        low++;
        mid++;
    }
    else{
        mid++;
    }
    }

}

int main(){
    vector<int> v;
    int n;
    cout << "enter the size of the array : ";
    cin >> n;

    // taking input
    cout << "enter the element of the array : ";
    for (int i = 0; i < n;i++){
        int element;
        cin >> element;
        v.push_back(element);
    }
    cout << "original array :";
    display(v);
    dutchFlagALgo(v);
    cout << "array after sort : ";
    display(v);
}
#include<iostream>
using namespace std;
#include<vector>
// 88leetcode
void display(vector<int> &b){
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

vector<int> merge(vector<int>arr1, vector<int>arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> arr(n+m);

    int i = 0;// arr1
    int j = 0;// arr2
    int k = 0;//arr
    while(i<n && j<m){  // last element index is n-1 and m-1 
        if(arr1[i]< arr2[j]){
            arr[k] = arr1[i];
            i++;
            // k++;
        }
        else{                   // arr1[i]>arr2[j]
            arr[k] = arr2[j];
            j++;
            // k++;
        }
        k++; // k++ is common for both loop so we put it here
    }
    // if n is greater then i =m-1; or m is greater then j =n-1;
    // for remaining element 
        while(j<m){
            arr[k] = arr2[j];
            j++;
            k++;
        }
    
        while(i<n){
            arr[k] = arr1[i];
            i++;
            k++;
        }
    return arr;
}

int main(){
    vector<int> arr1;
    int n1;
    cout << "Enter the size of vector : ";
    cin >> n1;
    
    cout << "first array : " << endl;
    for (int i = 0; i < n1;i++){
        int x;
        cin >> x;
        arr1.push_back(x);
    }
    display(arr1);

    vector<int> arr2;
    int n2;
    cout << "Enter the size of vector : ";
    cin >> n2;
 
    cout << "second array : " << endl;
    for (int i = 0; i < n2;i++){
        int x;
        cin >> x;
        arr2.push_back(x);
    }
    display(arr2);
    vector<int>arr = merge(arr1, arr2);
    display(arr);
}
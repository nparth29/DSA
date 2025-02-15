#include<iostream>
using namespace std;
#include<climits> // for INT_MIN
int main(){
    int n;
    cout << "enter the size of array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cout << "enrer the " << i << "th element : ";
        cin >> arr[i];
    }

    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int max = INT_MIN;
    // int max = arr[0];
    for (int i = 0; i < n; i++){
        if(max<arr[i]){
            max = arr[i];
        }   
    }
    cout << "The maximum value is : " << max;
}

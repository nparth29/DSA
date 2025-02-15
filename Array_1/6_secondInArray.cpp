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
    int sec_val;
    // int max = arr[0];
    // method 1
    for (int i = 0; i < n; i++){
        if(max<arr[i]){
            sec_val = max;
            max = arr[i];
        }   
    }

    // method 2
    int tmax = INT_MIN;
    for (int i = 0; i < n;i++){
        if(arr[i] != max && arr[i]!=sec_val && tmax<arr[i])
            tmax = arr[i];
    }
    cout << "The maximum value is : " << max<<endl;
    cout << "Second largest value is : " << sec_val<<endl;
    cout << "third largest val =" << tmax;
}

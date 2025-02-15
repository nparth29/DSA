#include<iostream>
using namespace std;
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

    int x;
    cout << "Enter the element you wnat to search : ";
    cin >> x;
    bool flag = false;
    for (int i = 0; i < n; i++){
        if(arr[i]==x){
            flag = true;
           
        }
    }
    if (flag==true)
        cout << "elemenr is present :)";
    else
        cout << "element is not present :(";
}
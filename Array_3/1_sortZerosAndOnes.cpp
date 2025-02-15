#include<iostream>
using namespace std;
#include<vector>


void display(vector<int> &b){
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

void method1_short01(vector<int> v){
    int nOF0 = 0;
    int nOF1 = 0;
    for (int i = 0; i < v.size();i++){
        if(v[i]==0)
            nOF0++;
        else
            nOF1++;
    }
    // filling the element
    for (int i = 0; i < v.size();i++){
        if(i<nOF0)
            v[i] = 0;
        else
            v[i] = 1;
    }
    cout << "sorted array using method 1 : ";
    display(v);
    cout << endl;
}


// Method 2: Sorting binary array using two-pointer approach
void method2_sort(vector<int> v) {
    int i = 0, j = v.size() - 1;

    while (i < j) {
        if (v[i] == 0) {
            i++;  // Move `i` forward if the current element is already 0
        } else if (v[j] == 1) {
            j--;  // Move `j` backward if the current element is already 1
        } else {
            // Swap elements when v[i] == 1 and v[j] == 0
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    cout << "Sorted array using method 2: ";
    display(v);
}


int main(){
    vector<int> v;
    int n;
    
    cout << "enter the size of the array : ";
    cin >> n;
    cout << "enter the elements : ";
    for (int i = 0; i < n;i++){
        int arr;
        cin >> arr;
        v.push_back(arr);
    }
    cout << "original array : ";
    display(v);
    
    method1_short01(v);
    method2_sort(v);
}
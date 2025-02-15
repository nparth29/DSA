#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
    Function to find the next permutation of the given array:
    
    1. **Find the Pivot**:
       - Traverse the array from the second last element to the first.
       - Find the first element (pivot) where the current element is less than the next element.
       - If no such element exists, the array is sorted in descending order, and the next permutation is simply the reverse of the current array.

    2. **Reverse the Suffix**:
       - The part of the array after the pivot is always in descending order. Reverse this part to make it ascending, as the smallest lexicographical order starts with an ascending sequence.

    3. **Swap the Pivot**:
       - Find the smallest element in the reversed suffix that is greater than the pivot element.
       - Swap this element with the pivot.
       - The array is now the next permutation.
*/

void display(vector<int>&arr){
    for (int i = 0; i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reversePartOfArray(vector<int>&arr,int i,int j){
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void nextPermutation(vector<int>&arr){
    // finding the pivoit
    // Step 1: Find the pivot index where nums[idx] < nums[idx + 1]
    int idx = -1;
    for (int i = arr.size() - 2; i >= 0;i--){
        if(arr[i]<arr[i+1]){
            idx = i;
            break;
        }
    }

    if(idx==-1){
        reversePartOfArray(arr, 0, arr.size() - 1);
    }

    // Step 3: Reverse the part of the array after the pivot index to make it ascending
    reversePartOfArray(arr, idx + 1, arr.size() - 1);

    // Step 4: Find the smallest element in the suffix that is greater than nums[idx]
    int j = -1;
    for (int i = idx + 1; i < arr.size();i++){
        if(arr[i]>arr[idx]){
            j = i;
            break;
        }
    }
    // swap
    int temp = arr[idx];
    arr[idx] = arr[j];
    arr[j] = temp;
    return;
}

int main(){
    vector<int> arr;
    int n;
    cout << "Enter the size of the array : ";
    cin>>n;

    cout << "enter the elements : ";
    for (int i = 0; i < n;i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }
    display(arr);
    nextPermutation(arr);
    display(arr);
}
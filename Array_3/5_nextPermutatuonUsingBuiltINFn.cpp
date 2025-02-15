#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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

void nextpermutation(vector<int> &nums) {
    int n = nums.size();
    int idx = -1;

    // Step 1: Find the pivot index where nums[idx] < nums[idx + 1]
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            idx = i;
            break;
        }
    }

    // Step 2: If no pivot is found, reverse the entire array (last permutation case)
    if (idx == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Reverse the part of the array after the pivot index to make it ascending
    reverse(nums.begin() + (idx + 1), nums.end());   // hame pivot ke ek index se aage se reverse krna hai =>  
    //nums.begin() ke value 0 usme hamne idx add kiya to ham index point pr aa gye ab hamne +1 kiya taki ham pivot ke ek aage wallhe index se reverse kr sake
    
    // Step 4: Find the smallest element in the suffix that is greater than nums[idx]
    for (int i = idx + 1; i < n; i++) {
        if (nums[i] > nums[idx]) {
            swap(nums[idx], nums[i]);
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    nextpermutation(v);

    cout << "The next permutation is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

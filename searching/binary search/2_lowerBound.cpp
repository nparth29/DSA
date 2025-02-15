#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1, 2, 4, 5, 9, 15, 18, 21, 24};
    int n = v.size();
    int x = 23;
    int flag = false;
    int lo = 0;
    int hi = n - 1;
    
    while(lo<=hi){
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x){
            flag = true;
            cout << v[mid - 1] << endl;
            break;
        }
        else if (v[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    if(flag == false)
        cout << v[hi];
}


/*

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a sorted vector (array) of integers
    vector<int> v = {1, 2, 4, 5, 9, 15, 18, 21, 24};
    int n = v.size();  // Get the size of the vector
    int x = 23;  // The target number we want to find in the vector

    bool found = false;  // Flag to check if x is found
    int lo = 0, hi = n - 1;  // Binary search bounds (low and high pointers)

    // Perform binary search to find x in the vector
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // Compute mid index to avoid overflow

        if (v[mid] == x) {  
            // If x is found, print the previous element (if exists)
            found = true;
            if (mid > 0) 
                cout << "Previous element: " << v[mid - 1] << endl;
            else 
                cout << "No previous element exists (x is the first element)." << endl;
            break;  // Exit the loop as we found x
        } 
        else if (v[mid] < x) {  
            // If x is greater, search in the right half
            lo = mid + 1;
        } 
        else {  
            // If x is smaller, search in the left half
            hi = mid - 1;
        }
    }

    // If x is not found, print the largest element smaller than x
    if (!found) {
        if (hi >= 0) 
            cout << "Largest element smaller than " << x << " is: " << v[hi] << endl;
        else 
            cout << "No smaller element exists (x is smaller than all elements)." << endl;
    }

    return 0;
}



*/
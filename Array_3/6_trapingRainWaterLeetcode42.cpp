// leetcode 42 : 
#include<iostream>
using namespace std;
#include<vector>


int trap3(vector<int>& height){
    int n = height.size();
    // previous greatest element array :
    int prev[n];  
    int max = height[0];
    for (int i = 1; i < n;i++){
        prev[i] = max;
    if(max<height[i])
        max = height[i];
        
    }
    // next greatest element array :
    
    prev[n - 1] = -1;
    max = height[n - 1];
    for (int i = n - 2; i >= 0;i--){
        if(max<prev[i]) prev[i] = max;

        if(max<height[i])
            max = height[i];
    }

    
    // calculating water
    int water = 0;
    for (int i = 1; i < n-1;i++){
        if(height[i]<prev[i])
            water += (prev[i] - height[i]);
    }
    return water;
}

int trap2(vector<int>& height){
    int n = height.size();
    // previous greatest element array :
    int prev[n];  
    int p_max = height[0];
    for (int i = 1; i < n;i++){
        prev[i] = p_max;
    if(p_max<height[i])
        p_max = height[i];
        
    }
    // next greatest element array :
    int next[n];
    next[n - 1] = -1;
    int n_max = height[n - 1];
    for (int i = n - 2; i >= 0;i--){
        next[i] = n_max;
        if(n_max<height[i])
            n_max = height[i];
    }

    for (int i = 0; i < n;i++){
        prev[i] = min(prev[i], next[i]);
    }

    // calculating water
    int water = 0;
    for (int i = 1; i < n-1;i++){
        if(height[i]<prev[i])
            water += (prev[i] - height[i]);
    }
    return water;
}

int trap1(vector<int>& height){
    int n = height.size();
    // previous greatest element array :
    int prev[n];  
    int p_max = height[0];
    for (int i = 1; i < n;i++){
        prev[i] = p_max;
    if(p_max<height[i])
        p_max = height[i];
        
    }
    // next greatest element array :
    int next[n];
    next[n - 1] = -1;
    int n_max = height[n - 1];
    for (int i = n - 2; i >= 0;i--){
        next[i] = n_max;
        if(n_max<height[i])
            n_max = height[i];
    }
    // minimum array :
    int mini[n];
    for (int i = 0; i < n;i++){
        mini[i] = min(prev[i], next[i]);
    }

    // calculating water
    int water = 0;
    for (int i = 1; i < n-1;i++){
        if(height[i]<mini[i])
            water += (mini[i] - height[i]);
    }
    return water;
}




int main(){
        int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = trap3(v);  // best method less space complexity 
    cout << " answer is : " << ans;
}
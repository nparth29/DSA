#include <bits/stdc++.h>
using namespace std;

/* -----------------------------------------------------------
   METHOD 1 CLASS 
   - Push reverse into vector
   - Then insert all elements of updated vector into set
------------------------------------------------------------*/
class MethodOne {
public:
    int reverse(int n){ 
        int r = 0;
        while(n > 0){
            r = r * 10;          // shift digits left
            r += (n % 10);       // add last digit
            n /= 10;             // drop last digit
        }
        return r;
    }

    int countDistinctIntegers(vector<int>& nums) {

        int originalSize = nums.size();   // freeze original size 

        // push reverse elements into vector
        for(int i = 0; i < originalSize; i++){
            int rev = reverse(nums[i]);
            nums.push_back(rev);
        }

        // insert all elements (original + reversed) into set
        unordered_set<int> s; 
        for(int i = 0; i < nums.size(); i++){ 
            s.insert(nums[i]); 
        } 
        return s.size();
    }
};


/* -----------------------------------------------------------
   METHOD 2 CLASS 
   - Insert original element directly into set
   - Insert reverse directly into set
   - No vector modification
------------------------------------------------------------*/
class MethodTwo {
public:
    int reverse(int n){ 
        int r = 0;
        while(n > 0){
            r = r * 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }

    int countDistinctIntegers(vector<int>& nums) {

        int originalSize = nums.size();
        unordered_set<int> s;

        for(int i = 0; i < originalSize; i++){
            int rev = reverse(nums[i]);

            // directly insert into set
            s.insert(nums[i]); 
            s.insert(rev);
        }
        return s.size();
    }
};


/* -----------------------------------------------------------
   MAIN FUNCTION
------------------------------------------------------------*/
int main() {

    // Example input
    vector<int> nums = {1, 13, 10, 12, 31};

    // Method 1 call
    MethodOne m1;
    vector<int> nums_copy1 = nums;  // copy to avoid modifying original
    int result1 = m1.countDistinctIntegers(nums_copy1);

    // Method 2 call
    MethodTwo m2;
    vector<int> nums_copy2 = nums;  // copy to avoid modifying original
    int result2 = m2.countDistinctIntegers(nums_copy2);

    // Print results
    cout << "Method 1 Result: " << result1 << endl;
    cout << "Method 2 Result: " << result2 << endl;

    return 0;
}

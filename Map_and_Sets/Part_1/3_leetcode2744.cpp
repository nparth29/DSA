#include <bits/stdc++.h>
using namespace std;

/* -----------------------------------------------------------
   METHOD 1 CLASS
   - For each word, compute its reverse and compare with the rest
   - No set used; nested loops count matching reverse pairs
------------------------------------------------------------*/
class MethodOne {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0; 
        for(int i = 0; i < n; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            for(int j = i + 1; j < n; j++){
                if(rev == words[j]) count++;
            }
        }
        return count; 
    }
};

/* -----------------------------------------------------------
   METHOD 2 CLASS
   - Build a set of all words
   - For each word, check if its reverse exists in set
   - If found, increment count and erase the actual word from set
   - Skip palindromes (assumes unique strings constraint)
------------------------------------------------------------*/
class MethodTwo {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0; 
        unordered_set<string> s;
        for(int i = 0; i < n; i++){
            s.insert(words[i]);
        }

        // we compare the rev of elements in array , inside the set
        // if it matches -> count++ and remove that actual element(arr) from set.
        // if string is palindrome -> continue (constraints: unique string in vector)
        for(int i = 0; i < n; i++){
            string rev = words[i]; // do not touch the vector element, create a copy
            reverse(rev.begin(), rev.end()); 
            if(rev == words[i]) continue; // to handle palindrome 
            if(s.find(rev) != s.end()){
                count++;
                s.erase(words[i]); // remove the actual element from set
            }
        }
        return count; 
    }
};

/* -----------------------------------------------------------
   METHOD 3 CLASS
   - One-pass using set:
   - For each word compute reverse; if reverse already in set -> count++
   - Otherwise insert the word into set
------------------------------------------------------------*/
class MethodThree {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0; 
        unordered_set<string> s;
        for(int i = 0; i < n; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if(s.find(rev) != s.end()) count++;
            else s.insert(words[i]);
        }
        return count;
    }
};


/* -----------------------------------------------------------
   MAIN: example usage calling all three methods
------------------------------------------------------------*/
int main() {
    // Example input - you can change this to test other cases
    vector<string> words = {"cd", "ac", "dc", "ca", "zz"}; 
    // Pairs: ("cd","dc"), ("ac","ca") ; "zz" is palindrome repeated twice -> depends on method logic

    // Method 1
    MethodOne m1;
    vector<string> copy1 = words; // not necessary (method doesn't modify), but safe
    int res1 = m1.maximumNumberOfStringPairs(copy1);

    // Method 2
    MethodTwo m2;
    vector<string> copy2 = words; // not necessary, safe
    int res2 = m2.maximumNumberOfStringPairs(copy2);

    // Method 3
    MethodThree m3;
    vector<string> copy3 = words; // not necessary, safe
    int res3 = m3.maximumNumberOfStringPairs(copy3);

    cout << "Method 1 Result: " << res1 << endl;
    cout << "Method 2 Result: " << res2 << endl;
    cout << "Method 3 Result: " << res3 << endl;

    return 0;
}

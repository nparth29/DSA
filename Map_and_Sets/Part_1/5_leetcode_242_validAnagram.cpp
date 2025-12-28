#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) 
            return false;

        unordered_map<char, int> map1; // frequency map for s

        for(int i = 0; i < s.length(); i++){
            map1[s[i]]++;
        }

        for(int i = 0; i < t.length(); i++){
            char ch = t[i];

            if(map1.find(ch) != map1.end()){
                map1[ch]--;
                if(map1[ch] == 0)
                    map1.erase(ch);  // remove character when count hits 0
            }
            else
                return false;       // FIX: must return false
        }

        if(map1.size() > 0) 
            return false;

        return true;
    }
};

int main() {
    Solution obj;

    string s1 = "anagram";
    string s2 = "nagaram";

    string s3 = "rat";
    string s4 = "car";

    cout << boolalpha;
    cout << "Is Anagram (s1, s2)? " << obj.isAnagram(s1, s2) << endl; // true
    cout << "Is Anagram (s3, s4)? " << obj.isAnagram(s3, s4) << endl; // false

    return 0;
}

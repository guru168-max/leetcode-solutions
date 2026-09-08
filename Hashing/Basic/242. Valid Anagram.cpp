// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false
// Constraints:

//     1 <= s.length, t.length <= 5 * 104
//     s and t consist of lowercase English letters.


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mpp;
        for(auto it:s)
        mpp[it]++;

       for(int i=0; i<t.size(); i++)
       {
        mpp[t[i]]--;
        
       }
       for(auto it:mpp)
       if(it.second!=0) return false;
       return true;
        
    }
};

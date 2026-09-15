// The power of the string is the maximum length of a non-empty substring that contains only one unique character.

// Given a string s, return the power of s.

 

// Example 1:

// Input: s = "leetcode"
// Output: 2
// Explanation: The substring "ee" is of length 2 with the character 'e' only.

// Example 2:

// Input: s = "abbcccddddeeeeedcba"
// Output: 5
// Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

 

// Constraints:

//     1 <= s.length <= 500
//     s consists of only lowercase English letters.

class Solution {
public:
    int maxPower(string s) {
        int cnt=1;
        int mx=1;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i-1]==s[i])
            cnt++;
            else
            {
                mx=max(mx,cnt);
                cnt=1;

            }
        }
         mx=max(mx,cnt);
        return mx;
        
    }
};

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

 

// Constraints:

//     1 <= s.length, p.length <= 3 * 104
//     s and p consist of lowercase English letters.


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        vector<int> store(26, 0);
        // Frequency of pattern
        for (int i = 0; i < m; i++) {
            store[p[i] - 'a']++;
        }
        int left = 0;
        int right = 0;
        int count = m;
        while (right < n) {
            // Add current character
            if (store[s[right] - 'a'] > 0) {
                count--;
            }
            store[s[right] - 'a']--;
            // Window size reached pattern size
            if (right - left + 1 == m) {
                // Anagram found
                if (count == 0) {
                    ans.push_back(left);
                }
                // Remove left character
                if (store[s[left] - 'a'] >= 0) {
                    count++;
                }
                store[s[left] - 'a']++;
                left++;
            }
            right++;
        }
        return ans;
    }
};

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".

// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

 

// Constraints:

//     1 <= s.length, t.length <= 200
//     s and t only contain lowercase letters and '#' characters.

 

// Follow up: Can you solve it in O(n) time and O(1) space?




class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_ptr = s.size() - 1;
        int p_ptr = t.size() - 1;

        int skipInS = 0;
        int skipInT = 0;

        while (s_ptr >= 0 || p_ptr >= 0) {

            // Find next valid character in s
            while (s_ptr >= 0) {

                if (s[s_ptr] == '#') {
                    skipInS++;
                    s_ptr--;
                } else if (skipInS > 0) {
                    skipInS--;
                    s_ptr--;
                } else {
                    break;
                }
            }

            // Find next valid character in t
            while (p_ptr >= 0) {

                if (t[p_ptr] == '#') {
                    skipInT++;
                    p_ptr--;
                } else if (skipInT > 0) {
                    skipInT--;
                    p_ptr--;
                } else {
                    break;
                }
            }

            // Both have valid characters
            if (s_ptr >= 0 && p_ptr >= 0 && s[s_ptr] != t[p_ptr]) {
                return false;
            }

            // One has a character, other doesn't
            if ((s_ptr >= 0) != (p_ptr >= 0)) {
                return false;
            }

            // Move to previous characters
            s_ptr--;
            p_ptr--;
        }

        return true;
    }
};

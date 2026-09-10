// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

//     Remove substring "ab" and gain x points.
//         For example, when removing "ab" from "cabxbae" it becomes "cxbae".
//     Remove substring "ba" and gain y points.
//         For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.
// Example 1:

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.

// Example 2:

// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20
// Constraints:

//     1 <= s.length <= 105
//     1 <= x, y <= 104
//     s consists of lowercase English letters.


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        stack<char> st;
        bool found = false;
        if (y >= x) {
            // First remove "ba"
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty() && st.top() == 'b' && s[i] == 'a') {
                    ans += y;
                    st.pop();
                    found = true;
                }
                if (found) {
                    found = false;
                    continue;
                }
                st.push(s[i]);
            }

            // Build remaining string
            string temp = "";
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());

            // Second pass remove "ab"
            for (int i = 0; i < temp.size(); i++) {
                if (!st.empty() && st.top() == 'a' && temp[i] == 'b') {
                    ans += x;
                    st.pop();
                    found = true;
                }
                if (found) {
                    found = false;
                    continue;
                }
                st.push(temp[i]);
            }
        } else {

            // First remove "ab"
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty() && st.top() == 'a' && s[i] == 'b') {
                    ans += x;
                    st.pop();
                    found = true;
                }
                if (found) {
                    found = false;
                    continue;
                }
                st.push(s[i]);
            }

            // Build remaining string
            string temp = "";
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());

            // Second pass remove "ba"
            for (int i = 0; i < temp.size(); i++) {

                if (!st.empty() && st.top() == 'b' && temp[i] == 'a') {
                    ans += y;
                    st.pop();
                    found = true;
                }
                if (found) {
                    found = false;
                    continue;
                }
                st.push(temp[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    string decodeString(string s) {
        // observations:- the digit may be the more than the 9 so we must digit
        // extractions brackets will tell me that whos are going to club me here
        // 3[a2[c]] :- before the c digit 2 so two times cc and then a overall
        // acc now before 3 add and reverse if there inside this
        // [x2[something]]; acc i was thinking that when ] ok wait..
        stack<char> st;
        int n = s.size();
       // string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ']') {
                // here i get the actually staring to ans ;
                string temp = "";
                // go till the the you did not get it's opposite ([)
                while (!st.empty() && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                // before that we must rreverse
                reverse(temp.begin(), temp.end());
                // pop first
                st.pop();
                // now we have the digit
                string digit = "";
                while (!st.empty() && isdigit(st.top())) {
                    digit += st.top();
                    st.pop();
                }
                // now reverse it
                reverse(digit.begin(), digit.end());
                int actuallDigit = stoi(digit);
                // now go it in the stack that current temp with actauuy digit
                while (actuallDigit--) {
                    for (char ch : temp) {
                        st.push(ch);
                    }
                }

            }
            //
            else {
                st.push(s[i]);
            }
        }
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

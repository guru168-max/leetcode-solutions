class Solution {
public:
    string reverseParentheses(string s) {
        /*
        we have given string that containt only lower case and bracket only
        when the string in the each pair of the matching parentheses,
        and we have to start the the reversing the string from the most inntermost valid 
        one
        and thar result must be containt only the string 
        and return it as string
        */
        //simple when the the closing start then start the reversing  till 
        // push into the stack
        stack<char>st;
       // stack<char>ans;
        string ans="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=')')
            {
                // till push the char or another
                st.push(s[i]);
            }
            else
            {
                // string temp="";
                // while(st.top()!='(')
                // {
                //     temp+=st.top();
                //     st.pop();
                // }
                //we reduce the time using the vectoer
                vector<char> temp;  // use vector to avoid repeated string concatenation
                while (st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }

                //here we get temp
                st.pop(); //here we remove the '('
                // push reversed substring back
                for (char ch : temp) {
                    st.push(ch);
                }

            }
        }
        string result = "";

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
        
    }
};

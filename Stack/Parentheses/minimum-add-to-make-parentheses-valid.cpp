class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<char>st;
        bool found=false;
        for(int i=0; i<n; i++)
        {
            if(!st.empty() && (st.top()=='(' && s[i]==')'))
            {
                st.pop();
                found=true;

            }

            else
            {
                st.push(s[i]);
            }

        }
        return st.size();
    }
};
//this will take the extra space O(N)
// we can do without using the extra space 
//balance wala logic 

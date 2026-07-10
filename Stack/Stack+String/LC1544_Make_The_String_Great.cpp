class Solution {
public:
    string makeGood(string s) {
        //we have to delete one upper with lower
        stack<char>st;
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            if(!st.empty() && (st.top()==s[i]+32 ||st.top()==s[i]-32))
            {
                st.pop();

            }  
            else
            st.push(s[i]);
            
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

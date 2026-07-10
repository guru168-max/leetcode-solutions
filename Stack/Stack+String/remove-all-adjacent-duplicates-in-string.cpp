class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        stack<char>st;
        bool found=false;
        for(int i=0; i<n; i++)
        {
            if(!st.empty() && (st.top()==s[i]))
            {
                st.pop();
                found=true;
            }
            if(found) {
                found=false;
                continue;
            }
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

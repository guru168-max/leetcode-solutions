class Solution {
public:
    string removeKdigits(string num, int k) {
        //order must be preserve
        //and when we get 0 then before one as long as it smaller or greater no matters
        //12345678
        //like if the top> then pop it and count 
        //119
        //1
        stack<char>st;
        int n=num.size();
        string ans="";
        for(int i=0; i<n; i++)
        {
            while(!st.empty() &&( st.top()>num[i] && k>0))
            {
                //pop and k-- we are used the k
                st.pop();
                k--;
            }
            st.push(num[i]); 
        }
         //if the at the buttom 0 having don't consider
        //and before that is there any k remaining this also we need to used
        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        //if the at the buttom 0 having don't consider

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        //reverse
        reverse(ans.begin(), ans.end());
        //000123456
        int index=-1;
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i]!='0'){
                index=i;
                 break;
            }

        }
        if(index==-1) return "0";
        return ans.substr(index);
    }
};

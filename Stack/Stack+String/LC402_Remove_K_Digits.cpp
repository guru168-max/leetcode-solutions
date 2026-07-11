class Solution {
public:
    string removeKdigits(string num, int k) {
// The relative order of the remaining digits must be preserved.
// If the stack top is greater than the current digit,
// remove it to make the number smaller.
// Remove the larger digit and consume one deletion.
// If deletions are still left,
// remove digits from the end.
// Build the answer from the stack.
// Reverse because the stack stores digits in reverse order.

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

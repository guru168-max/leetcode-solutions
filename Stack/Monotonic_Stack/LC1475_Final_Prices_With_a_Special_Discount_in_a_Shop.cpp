class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //in simple next nearest smalllest to right side
        int n=prices.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && st.top()>prices[i]) st.pop();
            if(!st.empty()) ans[i]=prices[i]-st.top();
            else ans[i]=prices[i];
            st.push(prices[i]);
        }
        return ans;
        
    }
};

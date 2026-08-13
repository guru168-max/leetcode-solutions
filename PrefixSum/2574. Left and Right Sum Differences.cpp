class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>postfix(nums.size());
        prefix[0]=nums[0];
        postfix[nums.size()-1]=nums[nums.size()-1];
        for(int i=1; i<nums.size(); i++)
        {
            prefix[i]=prefix[i-1]+nums[i];

        }

        // for(int i=0; i<nums.size(); i++)
        // {
        //     cout<<prefix[i]<<endl;
        //     cout<<postfix[i]<<endl;
        // }
         for(int i=nums.size()-2; i>=0; i--)
        {
            postfix[i]=postfix[i+1]+nums[i];

        }
        vector<int>ans(nums.size());
        for(int i=0; i<nums.size(); i++)
        {
            ans[i]=abs(prefix[i]-postfix[i]);
        }
        return ans;
        

        
    }
};

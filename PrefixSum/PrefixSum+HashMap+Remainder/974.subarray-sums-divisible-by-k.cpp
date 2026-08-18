class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int ans=0;

        int prefixSum=0;
        for(int i=0; i<n; i++)
        {
            prefixSum+=nums[i];
            //when prefix  sum getting -ve i need do as +ve
            int rem=prefixSum % k;
            if(rem<0)  rem+=k ;
            if(mpp.find(rem)!= mpp.end())
            {
                ans+=mpp[rem];
            }
            mpp[rem]++;  

        }
        return ans;
        
    }
};

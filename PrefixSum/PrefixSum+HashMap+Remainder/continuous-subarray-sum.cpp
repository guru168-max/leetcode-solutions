class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1; i<n; i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        //using this one create rem arrays
        unordered_map<int,int>mpp;   //first for the rem sum and second for the index
        mpp[0]=-1;
        for(int i=0; i<prefixSum.size(); i++)
        {
            if(mpp.find(prefixSum[i]%k)!=mpp.end())
            {
                //check that they are divisible by k or not
                // if(mpp[prefixSum[i]%k]% prefixSum[i]==0)
                // {
                //     return true;
                // }
                if(i-mpp[prefixSum[i]%k]>=2)
                {
                     return true;
                }
            }
            else
            mpp[prefixSum[i] % k]=i;
        }
        return false;
        
    }
};

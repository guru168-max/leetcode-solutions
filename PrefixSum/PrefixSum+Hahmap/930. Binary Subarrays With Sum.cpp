class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        //this is for the <prefixSum,count>
        int count=0;
        int currentSum=0;
        mpp[0]=1 ;//in case the sum=0 that must be the 0->1
        for(int i=0; i<n; i++)
        {
            currentSum+=nums[i];
            //now check currentSum-k ot lookup in hashmap 
            //then add that pointing count
            if(mpp.find(currentSum-goal)!=mpp.end())
            count+=mpp[currentSum-goal];
            //then currentSum add in the hashmap for storing 
            mpp[currentSum]++;
        }
        return count;
        
    }
};

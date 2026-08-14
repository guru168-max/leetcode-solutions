
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>pre;
        pre[0]=1;  //in future there might be case where prefixSum-k==0 AND that should be in the map 
        //so that 
        //we are storing in the map{prefixSum,countOfthatOne};
        int prefixSum=0;
        for(int i=0; i<n; i++)
        {
            prefixSum+=nums[i];
            int complement=prefixSum-k;
            //check if that is in the hash map
            if(pre.find(complement)!=pre.end())
            {
                count+=pre[complement];
            }
            pre[prefixSum]++;

        }
        return count;
        
    }
};

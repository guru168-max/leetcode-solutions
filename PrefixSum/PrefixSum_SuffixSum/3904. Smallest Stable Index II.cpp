class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        //we need to find max from left
        //so store the running maximum
        //
        //then we need min from right
        //we can find it while traversing from right
        //
        //then check
        //max-min <= k
        //
        //we need the first index
        //so traverse from left

        int n=nums.size();

        vector<int>prefix(n);

        prefix[0]=nums[0];

        for(int i=1; i<n; i++)
        {
            prefix[i]=max(prefix[i-1],nums[i]);
        }

        int mn=INT_MAX;

        vector<int>suffix(n);

        suffix[n-1]=nums[n-1];

        for(int i=n-2; i>=0; i--)
        {
            suffix[i]=min(nums[i],suffix[i+1]);
        }

        for(int i=0; i<n; i++)
        {
            if(prefix[i]-suffix[i]<=k)
            {
                return i;
            }
        }

        return -1;
    }
};

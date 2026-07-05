class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int ans=INT_MAX;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            //first step is that find the peak
            //before that we need to find the min keep it mid 
            if(nums[mid]>=nums[start])
            {
                //what does mean that i can suppose the start as my ans
                //why becuse it is the sorted
                ans=min(ans,nums[start]);
                start=mid+1;
            }
            else
            {
                //why we are taking the two times ans becuse in case of the 
                //above case false means definely we are getting this side
                ans=min(ans,nums[mid]);
                end=mid-1;
            }
        }
        return ans;
        
    }
};

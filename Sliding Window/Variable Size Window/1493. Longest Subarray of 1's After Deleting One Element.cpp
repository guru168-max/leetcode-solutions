class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //what you can say that i need to find those subarrays who have the max one 
        //0 return the longest one
        //when i get one still go forward when i get second wait
        //till this one len-1 this is the valid one subarrays
        //look at the left if it is the 0 then cnt --  and left ++
        //and then right must forward
        //it mean that when the cnt>1  time to shrink the window with checking that left ==0 mean need to cnt--   rest of the left ++;
    
        int left=0;
        int ans=0;
        int cnt=0;
        for(int right=0; right<nums.size(); right++)
        {
            if(nums[right]==0)
            cnt++;
            while(cnt>1)
            {
                if(nums[left]==0)
                cnt--;
                left++;
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};

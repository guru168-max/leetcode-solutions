// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

 

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.
//     0 <= k <= nums.length

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //brute force check the till k 's o's it take O(n^2)
        int cnt=0;
        int left=0;
        int mx=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            cnt++;
            while(cnt>k)
            {
                if(nums[left]==0)
                cnt--;
                left++;
            }
            mx=max(mx,i-left+1);
        }
        return mx;


        

};

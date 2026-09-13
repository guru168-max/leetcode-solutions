// You are given an array nums consisting of positive integers.
// We call a subarray of an array complete if the following condition is satisfied:
// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
// Return the number of complete subarrays.
// A subarray is a contiguous non-empty part of an array.
// Example 1:
// Input: nums = [1,3,1,2,2]
// Output: 4
// Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

// Example 2:
// Input: nums = [5,5,5,5]
// Output: 10
// Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.

// Constraints:

//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 2000


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        //first count all the one 
        //then first goad is that you reach at least those who distinct==whole distincs
        //then this + ans rest n-current indx from that also valid the
        //for the next same just check that distinct left or not and then
        //just left one by one move
        

        unordered_map<int,int>mpp;
        for(auto it:nums)
        mpp[it]++;

        int totalDist=mpp.size();
        mpp.clear();


        int left=0;
        int ans=0;
        int dist=0;

        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;

            if(mpp[nums[i]]==1)
            dist++;

            while(dist==totalDist)
            {
                ans+=nums.size()-i;
                mpp[nums[left]]--;

                if(mpp[nums[left]]==0)
                dist--;

                left++;

            }
        }
        return ans;
    }
};

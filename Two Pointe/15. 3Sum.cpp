// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
//such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

 

// Constraints:

//     3 <= nums.length <= 3000
//     -105 <= nums[i] <= 105

 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>stt;
        for(int i=0; i<nums.size(); i++)
        {

            unordered_set<int>st;
            for(int j=i+1; j<nums.size(); j++)
            {
                if(st.find(-(nums[i]+nums[j])) !=st.end())
                {
                    //if this follow then add this one in the set before like sort 
                    vector<int>temp={nums[i],-(nums[i]+nums[j]),nums[j]};
                    sort(temp.begin(),temp.end());
                    stt.insert(temp);
                }
                //other wise add in this in the set
                st.insert(nums[j]);

            }
        }
        vector<vector<int>>ans(stt.begin(),stt.end());
        return ans;

    }
};

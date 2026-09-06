// Given a collection of candidate numbers (candidates) and a target number (target),
//find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

 

// Constraints:

//     1 <= candidates.length <= 100
//     1 <= candidates[i] <= 50
//     1 <= target <= 30



class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void solve(vector<int>& candidates, int target,vector<int>&path,int start,int n,int sum)
    {
        if(sum==target)
        {
            ans.push_back(path);
            return;
        }
        if(sum>target)
        {
          //when the sum > target no meaning to check
            return;
        }

        for(int i=start; i<n; i++)
        {
            //skipping the duplicates
            if(i > start && candidates[i] == candidates[i - 1])
                continue;
          //add the current one
            path.push_back(candidates[i]);
          //explore the another choice
            solve(candidates,target,path,i+1,n,sum+candidates[i]);
            //pop when you one's used
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,path,0,candidates.size(),0);
        return ans;
    }
};

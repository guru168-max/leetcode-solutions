class Solution {
public:
    void generateAllSub(vector<int>& nums, vector<vector<int>>& ans,
                        vector<int>& current, int index, int n) {
        if (index == n) {
            // check if this exist in the ans or not
            //[1,2,2] == current [1,2,2]
            bool found = false;
            for (auto& subset : ans) {
                if (subset == current) {
                    found = true;
                    break;
                }
            }
            if (!found)
                ans.push_back(current);

            return;
        }

        // then for the picking the each of the element
        current.push_back(nums[index]);
        // call for the pick
        generateAllSub(nums, ans, current, index + 1, n);
        // we are using the ref so need to pop last one or undo
        current.pop_back();

        // then call for the not pick
        generateAllSub(nums, ans, current, index + 1, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        int n = nums.size();
        generateAllSub(nums, ans, current, 0, n);
        return ans;
    }
};

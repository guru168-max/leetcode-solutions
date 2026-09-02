class Solution {
public:
    void allSubsets(vector<int>& nums , int n, int index, vector<int>&current ,vector<vector<int>>&ans)
    {
        if(index==n)
        {
            ans.push_back(current);
            return;
        }

        //pick
        current.push_back(nums[index]);
        //call for the oick onne
        allSubsets(nums,n,index+1,current,ans);

        //when i reach at the end then i will meet here so next time i need 
        //do call for the not pick but before that we  are using the call by ref 
        //so undo /backtrack
        current.pop_back();
        //then call for the not pick one

        allSubsets(nums,n,index+1,current,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>current;
        allSubsets(nums,n,0,current,ans);
        return ans;
        
    }
};

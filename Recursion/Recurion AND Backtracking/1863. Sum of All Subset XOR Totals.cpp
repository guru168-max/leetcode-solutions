class Solution {
public:
    int totalSum=0;
    void subsetsXOR(vector<int>&nums,int currentXOR, int index, int n)
    {
        if(index==n)
        {
            totalSum+=currentXOR;
            return ;
        }

        //call for the pick and each of the levels without pass by ref we want each time with local one
    subsetsXOR(nums,currentXOR^nums[index],index+1,n);
    //for not pick
    subsetsXOR(nums,currentXOR,index+1,n);
    }
    int subsetXORSum(vector<int>& nums) {
        int currentXOR=0;
        int n=nums.size();
        subsetsXOR(nums, currentXOR ,0 ,n);
        return totalSum;    
    }
};

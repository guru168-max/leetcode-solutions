class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        //i am going to choose for each of the diff irrepective
        //this will give me the O(n^2)
        //when i get the min result when i have the max one element 
        sort(nums.begin(),nums.end() ,greater<>());
        int n=nums.size();
        int ans=INT_MAX;
        if(k==1) return 0;
        int index=k-1;
        for(int i=0; i<=n-k; i++)
        {
            ans=min(ans,nums[i]-nums[index]);
            index++;
        }
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;
int countAllSumSub(vector<int>&nums, int index, int n, int target, int &sum)
{
    if(index==n){
        return sum==target?1:0;
    }

    sum+=nums[index];
    //pick
    int pick=countAllSumSub(nums,index+1,n,target,sum);
    //this is the for backtrack
    sum-=nums[index];

    //now this is the for not pick(-)
    sum-=nums[index];

    //then call for the not pick one
    int not_pick=countAllSumSub(nums,index+1,n,target,sum);
    //this is for the undo not pick
    sum+=nums[index];


    return pick + not_pick;
}

int main()
{
    vector<int> nums={1,1,1,1,1};
    int target=1;
    int n=nums.size();
    int sum=0;
    int ans=countAllSumSub(nums,0,n,target,sum);
    cout<<"ANSWER :"<<ans;
     return 0;
}

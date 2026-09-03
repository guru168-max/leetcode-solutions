// Problem 04 — Count Subsets With Sum K
// Problem Statement
// You are given an array of positive integers arr of size n and an integer target.
// Find the number of subsets whose elements add up exactly to target.
// Each element can be used at most once.
// Return the total number of valid subsets.
// Example 1
// Input:
// arr = [1, 2, 3]
// target = 3

// Output:
// 2
// Explanation:
// [1, 2] → 3
// [3]    → 3
// So the answer is 2.
// Example 2
// Input:
// arr = [2, 3, 5]
// target = 5

// Output:
// 2
// Explanation:
// [2, 3] → 5
// [5]    → 5
// Example 3
// Input:
// arr = [1, 1, 1, 1]
// target = 2

// Output:
// 6
// Because there are 6 different ways to choose two of the four elements.
// Constraints
// 1 <= n <= 20
// 1 <= arr[i] <= 100
// 0 <= target <= 1000


#include<bits/stdc++.h>
using namespace std;

int countSubSetSum(vector<int>&nums, int index, int n, int target, int &sum)
{
    if(sum==target) return 1;
    if(index==n) return 0;
    sum+=nums[index];
    int pick=countSubSetSum(nums,index+1,n,target,sum);
    sum-=nums[index];
    int not_pick=countSubSetSum(nums,index+1,n,target,sum);
    return pick + not_pick;
}
int main()
{
    vector<int> nums={1, 2, 3, 4};
    int target=5;
    int n=nums.size();
    int sum=0;
    int ans=countSubSetSum(nums,0,n,target,sum);
    cout<<"ANS :" <<ans;

}

// You are given an integer array nums and an integer x. In one operation,
//you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. 
//Note that this modifies the array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
// Example 1:

// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

// Example 2:

// Input: nums = [5,6,7,8,9], x = 4
// Output: -1

// Example 3:

// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 104
//     1 <= x <= 109


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        // minimum number choose from the given arrays so that we can make x
        // zero so here if i make each of the sub arrays and then check that
        // totalSum of that subarray == totalSum-x
        // then i think this will give us the answer
        //
        //{1}{1}{4}{2}{3}
        //{1,1}{1,4}{1,2}{1,3}
        //{1,1,4}{1,1,2}{1,1,3}
        //{1,1,4,2}{1,1,4,3}
        //{1,1,4,2,3}
        //
        // if check which one is giving me the sum == totalSum-x
        // then take its length
        // and find the longest one
        // because we need to remove the minimum number
        //
        // brute force O(n^2)
        //
        // using the sliding window
        // like the currentWindowSum > needToFindWindow then shrink
        // if the currentWindowSum == needToFindWindow
        // then find the max length
        //
        // answer = total size - max length

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        int maxLength = 0;
        if(x > totalSum)
        return -1;

        int needToFindWindow = totalSum - x;
        if(needToFindWindow==0) return nums.size();
        int currentWindowSum = 0;
        for (int right = 0; right < nums.size(); right++) {
            currentWindowSum += nums[right];
            while (currentWindowSum > needToFindWindow) {
                currentWindowSum -= nums[left];
                left++;
            }
            if (currentWindowSum == needToFindWindow) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        return maxLength == 0 ? -1 : nums.size() - maxLength;
    }
};

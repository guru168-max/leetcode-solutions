// Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. 
// You may return the answer in any order.
// Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
// Example 1:
// Input: n = 3, k = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.

// Example 2:
// Input: n = 2, k = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

// Constraints:

//     2 <= n <= 9
//     0 <= k <= 9

  
class Solution {
public:
    vector<int> ans;

    void solve(int num, int len, int n, int k)
    {
        // WHEN LENGTH BECOMES N
        // MEANS WE HAVE BUILT THE COMPLETE NUMBER
        if(len == n)
        {
            ans.push_back(num);
            return;
        }

        int current = num % 10;

        // WHEN I STAND AT CURRENT DIGIT
        // I HAVE TWO CHOICES:
        // CURRENT-K OR CURRENT+K

        // IF CURRENT-K IS VALID
        // THEN PICK THIS PATH
        if(current - k >= 0)
        {
            solve(num * 10 + (current - k), len + 1, n, k);
        }

        // IF CURRENT+K IS VALID
        // THEN PICK THIS PATH
        //
        // WHEN K = 0, CURRENT-K AND CURRENT+K
        // ARE THE SAME, SO WE DON'T TAKE THIS PATH AGAIN
        if(current + k <= 9 && k != 0)
        {
            solve(num * 10 + (current + k), len + 1, n, k);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k)
    {
        // I CAN START THE NUMBER FROM 1 TO 9
        // BECAUSE THE FIRST DIGIT CANNOT BE 0
        //
        // FOR EACH FIRST DIGIT,
        // SOLVE WILL EXPLORE BOTH POSSIBLE PATHS
        // CURRENT-K AND CURRENT+K
        //               1
        //              /  \       EACH TIME I HAVE TO CHOICES CURRENT-1 OR CURRENT+1
        //             1-7  1+7

        for(int i = 1; i <= 9; i++)
        {
            solve(i, 1, n, k);
        }

        return ans;
    }
};

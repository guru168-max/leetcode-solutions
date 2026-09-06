// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.
// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
// Constraints:

//     1 <= n <= 20
//     1 <= k <= n


class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void solve(int n,vector<int>&path,int start,int k)
    {
        //when the size of the path ==k add this ans and return
        if(path.size()==k)
        {
            ans.push_back(path);
            return;
        }
        //now go each of the element as explorations
        for(int i=start; i<=n; i++)
        {
            //add the currene on in the path
            path.push_back(i);
            //then call for the next one using the i+1
            solve(n,path,i+1,k);

            //when i go for the each of then i need to like pop(used one)
            //1-> {1,2}{1,3}{1,4}
            //now i have to pop that one (1)
            path.pop_back();
    }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(n,path,1,k);
        return ans;
    }
};

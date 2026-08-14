class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        // step 1:- marks 0 as -1 and rest as 1
        vector<int> markArray(nums.size(), 1);

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
                markArray[i] = -1;
        }

        // step 2:- get prefix sum
        vector<int> prefix(n);

        prefix[0] = markArray[0];

        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] + markArray[i];
        }

        // step 3:- suppose I have prefix sum
        // -1,0,1,2,3,4,3,2,1
        //
        // now I can observe that first time 1 is at index 2
        // and again 1 is at index 8
        //
        // what does this mean?
        // prefix[2] == prefix[8]
        //
        // so:
        // prefix[8] - prefix[2] = 0
        //
        // this means between index 2 and index 8
        // the internal sum is 0
        //
        // because:
        // 0 -> -1
        // 1 -> +1
        //
        // sum 0 means equal number of 0 and 1
        //
        // so the actual subarray is:
        // index 2 + 1 to index 8
        //
        // [1,1,1,0,0,0]
        //
        // length = current_index - first_time_stored_index
        //        = 8 - 2
        //        = 6
        //
        // I need the maximum length,
        // so every time I find the same prefix sum
        // I calculate the length and update max.

        // step 4:- store prefix sum with its first index
        unordered_map<int,int> mpp;

        // before the array starts prefix sum is 0
        // its index is -1
        //
        // for example [0,1]
        // prefix = [-1,0]
        //
        // when current prefix becomes 0,
        // 0 already exists in hashmap at index -1
        //
        // length = current_index - first_index
        //        = 1 - (-1)
        //        = 2

        mpp[0] = -1;

        int mxLn = 0;

        for(int i = 0; i < n; i++)
        {
            if(mpp.find(prefix[i]) != mpp.end())
            {
                // same prefix found
                // so sum between them is 0
                //
                // calculate the length
                // and take maximum

                mxLn = max(mxLn, i - mpp[prefix[i]]);
            }
            else
            {
                // first time this prefix comes
                // store its index
                //
                // don't update it later because
                // first index gives the maximum length

                mpp[prefix[i]] = i;
            }
        }

        return mxLn;
    }
};

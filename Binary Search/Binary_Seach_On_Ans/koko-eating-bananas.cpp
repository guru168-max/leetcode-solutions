#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // this will tell us how much Totaltime it take if we divide
    long long timeRequ(vector<int>& piles, int mid) {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += ceil((double)piles[i] / mid);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = 0;

        // find the maximum pile value (range)
        //  int rangeValue = 0;
        //  for (int x : piles)
        //  rangeValue = max(rangeValue, x);
        int rangeValue=*max_element(piles.begin(), piles.end());

        int start = 1;
        int end = rangeValue;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long value = timeRequ(piles, mid);

            if (value <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

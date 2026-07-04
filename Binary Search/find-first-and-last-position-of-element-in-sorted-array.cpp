class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

   
        // int first=-1;
        // int last=-1;
        // for(int i=0; i<n; i++)
        // {
        //     if(arr[i]==target)
        //     {
        //         first=i;
        //         break;
        //     }
        // }
        //  for(int i=n-1; i>=0; i--)
        // {
        //     if(arr[i]==target)
        //     {
        //         last=i;
        //         break;
        //     }
        // }
        // // if(first==-1 && last==-1)
        // // {
        // //     return {-1,-1};
        // // } 
        // return {first ,last};

         int n = nums.size();
        int first = -1, last = -1;

        // Find first occurrence
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;  // search on the left side
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // Find last occurrence
        start = 0; 
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                last = mid;
                start = mid + 1;  // search on the right side
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return {first, last};
    }
};

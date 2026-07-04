class Solution {
public:
    int search(vector<int>& nums, int target) {
        //i know that this is the rotated sorted
        //5,6,7,0,1,2,3
        //. . . .|. . . 
        //n=7
        //start=0 and end=6 mid=3   target=2
        //check those who is sorted like this 
        //if the  start>mid -> this current part is unsorted skip this 
        //and go else how and check nums[mid] and nums[end] this lies
        //algo:-
        //if the start>mid skip and go else wala part
        //now in else wala part check that element is between then
        //arr[mid]>=target && arr[end]<=target
        //if this follow then i have just look this onely again
        //so start=mid and end mid-1
        int n=nums.size();
        int start=0;
        int end=n-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            //now check which one part is sorted 
            //if the start>mid it mean that right part is sorted
            //if start<=mid left part is sorted
            if(nums[start]<=nums[mid])
            {
                //hey i am sure that i want search in this part
                //if my target lies between me then end wala part must be skip
                if(nums[start]<=target && nums[mid]>target)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
            //this is the right part is sorted

            else
            {
                if(nums[mid]<target && nums[end]>=target)
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }

            }
        }
        return -1;
    }
};

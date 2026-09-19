// You are given an integer array height of length n. 
// There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case,
//   the max area of water (blue section) the container can contain is 49.

// Example 2:

// Input: height = [1,1]
// Output: 1

 

// Constraints:

//     n == height.length
//     2 <= n <= 105
//     0 <= height[i] <= 104



  class Solution {
public:
    int maxArea(vector<int>& height) {
        //step 1:- i need the min height with max index dis
        //step 2:- when i get the min height 
        //step 3:- when i get the height less that the right so 
        //by defult i am going to loos the dis why not go ahead left++

        int left=0;
        int right=height.size()-1;
        int area=0;
        while(left<right)
        {
            area=max(area,min(height[left],height[right])*(right-left));
            if(height[left]<height[right]) left++;
            else right--;
        }
        return area;
    }
};

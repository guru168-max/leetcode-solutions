// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true

// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:

// Input: s = "abc"
// Output: false

 

// Constraints:

//     1 <= s.length <= 105
//     s consists of lowercase English letters.


class Solution {
public:
    bool checkPalindrom(string &s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            return false;
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        //
        //at most one char do we need to delete/skip from it
        //i just confirm that if this current char are trying to oppose for making 
        //palinddrom then need to skip and check rest of same for the check on both sides
        //but when the from the left side we need to pass current+1 and same the the right prt
        //for the right one right+1 and start as it
       //ex:-
        //1st:- abcdca if we only go from left part then this will get correct one but what if
        //2nd:- acdcba if we did not go from the right part then only goes from the left then it will giving me the wrong
        //so need go from the both sides

        int n=s.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else if(s[start]!=s[end])
            {
                return checkPalindrom(s,start+1,end)||checkPalindrom(s,start,end-1);
            }
        }
        return true;
    }
};

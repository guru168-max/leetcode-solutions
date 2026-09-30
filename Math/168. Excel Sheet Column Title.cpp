// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...

 

// Example 1:

// Input: columnNumber = 1
// Output: "A"

// Example 2:

// Input: columnNumber = 28
// Output: "AB"

// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

 

// Constraints:

//     1 <= columnNumber <= 231 - 1

class Solution {
public:
    string convertToTitle(int columnNumber) {
        //53%26->1
        //1%26->1
        //when we get the >0 here stop
        //for that 2
        //use the char 'A'+rem-1
        //suppose 'A'+2-1='B'
        //32
        string ans="";
        while(columnNumber>0)
        {
            int remainder=columnNumber%26;
            if(remainder==0)
            {
                ans+='Z';
                columnNumber=columnNumber/26-1;

            }
            else
            {
                ans+='A'+remainder-1;
                columnNumber/=26;
            }

        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

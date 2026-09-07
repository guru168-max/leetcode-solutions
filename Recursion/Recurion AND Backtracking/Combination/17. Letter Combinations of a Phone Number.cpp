// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
//Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]

 

// Constraints:

//     1 <= digits.length <= 4
//     digits[i] is a digit in the range ['2', '9'].



class Solution {
public:
    vector<string>ans;
    string path;
    void solve(string &digits,int index)
    {
        // Map each digit to its possible characters
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        // If index reaches the end, all digits have been processed
        if(index==digits.size())
        {
            // Add the completed combination to the answer
            ans.push_back(path);
            return;
        }

      // Convert the current digit character into an integer
        int digit=digits[index]-'0';

        // Explore every possible character for the current digit
        for(char ch:mapping[digit])
        {
            // Add the current character to the path
            path.push_back(ch);

            // Recursively process the next digit
            solve(digits,index+1);

           // Backtrack by removing the current character
           path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        //edge case for an empty
        if(digits.empty()) return {};
        solve(digits,0);
        return ans;
    }
};

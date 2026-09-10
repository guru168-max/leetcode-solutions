// You are given a string s and an integer k,
//a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, 
//causing the left and the right side of the deleted substring to concatenate together.
// We repeatedly make k duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.

// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"

// Example 3:

// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps
// Constraints:

//     1 <= s.length <= 105
//     2 <= k <= 104
//     s only contains lowercase English letters.



class Solution {
public:
    string removeDuplicates(string s, int k) {
        //we have the string and interger k
        //if i use the k times for the removal then 
        //then the time complexity will o(n*k)
        //space complexity O(n)
        //deeedbbcccbdaa
        //here the first goes like 
        //d then check the d==e no
        // then goes in the stack
        //de==e
        //when e goes then e same then both are not stack one and curren
        //when e==e then before one pop an dcurrnt one push
        //then pop=1
        //e=e yes then pop=2 then still the left in the e then 
        //e==d not then then we have to store the before on the then compare the 
        //if e==before one
        //this is fail so wwe need to wait till the k means store the same till the k
        //when it will reach then start the poping 


    //      stack<char> st;
    //     for(int i = 0; i < s.size(); i++) {
    //         st.push(s[i]);

    //         if(st.size() >= k) {
    //             int count = 0;
    //             vector<char> temp;

    //             while(count < k && !st.empty()) {
    //                 char ch = st.top();
    //                 st.pop();
    //                 temp.push_back(ch);

    //                 if(ch == s[i]) {
    //                     count++;
    //                 } else {
    //                     break;
    //                 }
    //             }

    //             if(count != k) {
    //                 for(int j = temp.size()-1; j >= 0; j--) {
    //                     st.push(temp[j]);
    //                 }
    //             }
                
    //         }
    //     }
    //     string ans = "";
    //     while(!st.empty()) {
    //         ans += st.top();
    //         st.pop();
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    int n=s.size();
    stack<pair<char,int>>st;
    for(int i=0; i<n; i++)
    {
        if(!st.empty() && st.top().first==s[i])
        {
            st.top().second++;
            if(st.top().second==k)
            {
                st.pop();
            }
        }
        else
        {
        st.push({s[i],1});
        }

    }

    string result = "";
    while(!st.empty())
    {
    auto p = st.top();
    st.pop();
    result += string(p.second, p.first);
    }
     reverse(result.begin(), result.end());
     return result;

   }
};

// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

 

// Constraints:

//     1 <= words.length <= 500
//     1 <= words[i].length <= 10
//     words[i] consists of lowercase English letters.
//     k is in the range [1, The number of unique words[i]]

 class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       //firsrly i will count all word with the help of the hashmap
       //and then sort it on the basis of the freq
       //and then just return k word 
       unordered_map<string,int> mpp;
       for(auto it:words)
       {
        mpp[it]++;
       }

       //then i need to use the lambd expression for the sorting 
       vector<pair<string, int>> arr(mpp.begin(), mpp.end());
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
        return a.second > b.second;

         return a.first < b.first;
        });
       //and then just take an ans arrays the go till k while adding and then return ans
       vector<string>ans;
      for(int i=0; i<k; i++)
      {
        ans.push_back(arr[i].first);
      }
        return ans;
    }
    // //time complesity:- O(NlogN)
    // //space :- O(N)

};

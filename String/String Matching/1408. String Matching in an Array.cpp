class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        //appraoch 1:- choose ith index and then check if this present in other one except
        //this current one f having the  add to the second one which having in the set
        

        int n=words.size();
        vector<string>ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                string temp=words[i];
                if(i==j) continue;
                 if(words[j].find(temp)!=string::npos)
                {
                ans.push_back(temp);
                break;
                }
            }
        }
        return ans;
    }
};

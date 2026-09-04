class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //if the weight of the any person more than the limit for sure that need sigle boat
        // at single time we can carry only two people with in the limited weight
        sort(people.begin(),people.end());
        //3,3,4,5  l=5
        //1,2,2,3 l=3
        int n=people.size();
        int boats=0;
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            if(people[start]+people[end]==limit)
             {
                end--;
                start++;
                boats++;
             }
           else if(people[start] + people[end] > limit)
            {
               
                end--;
                boats++;
            }
            else{
            start++;
            end--;
            boats++;
            }
        }
        return boats;
    }
};

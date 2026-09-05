class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //EACH BLOCK I NEED TO HOW MANY RECOLORS ARE THERE
        //WHEN THE LENGTH==K THEN NEED TO MOVE
        int left=0;
        int mn=INT_MAX;
        int cnt=0;
        for(int i=0; i<blocks.size(); i++)
        {
            if(blocks[i]=='W') cnt++;
            while(i-left+1==k)
            {
                mn=min(cnt,mn);
                if( blocks[left]=='W')
                cnt--;
                left++;
            }

        }
        return mn;
        
    }
};

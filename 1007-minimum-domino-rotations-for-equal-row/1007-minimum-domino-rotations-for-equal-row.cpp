class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=INT_MAX;
        int n=tops.size();
        
        for(int i=1;i<=6;i++)
        {
            int total=0; //tells if i is present in n different places or not
            int c1=0; //count of tops who dont have i
            int c2=0; //count of bottoms who dont have i
            
            for(int j=0;j<n;j++)
            {
                if(tops[j]==i || bottoms[j]==i)
                {
                    total++;
                    if(tops[j]!=i)
                        c1++;
                    if(bottoms[j]!=i)
                        c2++;
                }
            }
            if(total==n)
                ans=min(ans,min(c1,c2));
        }
        
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
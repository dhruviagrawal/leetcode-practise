class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>next(2,vector<int>(3,0)), curr(2,vector<int>(3,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                for(int c=1;c<=2;c++)
                {
                    int maxp;
                    if(b)
                    {
                        int buy=-prices[i]+next[0][c] ;
                        int nb=next[1][c];
                        maxp=max(buy,nb);
                    }
                    else
                    {
                        int s=prices[i]+next[1][c-1] ;
                        int ns=next[0][c] ;
                        maxp=max(s,ns);
                    }
                    curr[b][c]=maxp;
                }
            }
            next=curr;
        }
        
        return next[1][2];
    }
};
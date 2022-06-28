class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                for(int c=1;c<=k;c++)
                {
                    int maxp;
                    if(b)
                    {
                        int buy=-prices[i]+dp[i+1][0][c] ;
                        int nb=dp[i+1][1][c];
                        maxp=max(buy,nb);
                    }
                    else
                    {
                        int s=prices[i]+dp[i+1][1][c-1] ;
                        int ns=dp[i+1][0][c] ;
                        maxp=max(s,ns);
                    }
                    dp[i][b][c]=maxp;
                }
            }
        }
        
        return dp[0][1][k];
    }
};
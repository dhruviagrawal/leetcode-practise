class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
       
        dp[n][0]=dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                int maxp=0;
                if(b)
                {
                    int b=-prices[i]+dp[i+1][0];
                    int nb=dp[i+1][1];
                    maxp=max(b,nb);
                }
                else
                {
                    int s=prices[i]+dp[i+1][1];
                    int ns=dp[i+1][0];
                    maxp=max(s,ns);
                }
                dp[i][b]=maxp;
            }
        }
        
        return dp[0][1];
    }
};
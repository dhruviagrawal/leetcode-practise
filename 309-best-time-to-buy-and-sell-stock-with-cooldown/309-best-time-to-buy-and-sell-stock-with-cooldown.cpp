class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        // return f(0, 1, prices, dp);
        for(int i=n-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                if(b)
                {
                    dp[i][b]=max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                }
                else
                {
                    dp[i][b]=max(prices[i]+dp[i+2][1] , dp[i+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};
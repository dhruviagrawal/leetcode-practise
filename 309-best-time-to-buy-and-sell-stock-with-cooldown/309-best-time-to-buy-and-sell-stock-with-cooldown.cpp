class Solution {
public:
    int f(int i, int b, vector<int>&a, vector<vector<int>>&dp)
    {
        if(i>=a.size())
            return 0;
        if(dp[i][b]!=-1)
            return dp[i][b];
        if(b)
        {
            return dp[i][b]=max(-a[i]+f(i+1,0,a,dp) , f(i+1,1,a,dp));
        }
        else
        {
            return dp[i][b]=max(a[i]+f(i+2,1,a,dp) , f(i+1,0,a,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0, 1, prices, dp);
    }
};
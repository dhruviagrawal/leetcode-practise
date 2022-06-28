class Solution {
public:
    int f(int i, int t, vector<int>&a, int n, int k, vector<vector<int>>&dp)
    {
        if(i==n || t==2*k)
            return 0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        if(t%2==0)
        {
            return dp[i][t]=max(-a[i]+f(i+1, t+1, a, n, k, dp),f(i+1, t, a, n, k, dp));
        }
        else
        {
            return dp[i][t]=max(a[i]+f(i+1, t+1, a, n, k, dp),f(i+1, t, a, n, k, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return f(0, 0, prices, n, k, dp);
    }
};
class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices, vector<vector<int>>&dp, int fee)
    {
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        int maxp;
        if(buy)
        {
            int b=-prices[ind]+solve(ind+1, 0, prices,dp,fee);
            int nb=solve(ind+1, 1, prices,dp,fee);
            maxp=max(b,nb);
        }
        else
        {
            int s=prices[ind]-fee+solve(ind+1, 1, prices, dp, fee);
            int ns=solve(ind+1, 0, prices, dp, fee);
            maxp=max(s,ns);
        }
        return dp[ind][buy]=maxp;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int maxp=solve(0,1, prices,dp, fee);
        return maxp;
    }
};
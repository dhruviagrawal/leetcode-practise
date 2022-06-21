class Solution {
public:
    int solve(int ind, int t, vector<int>&coins,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(t%coins[0]==0)
                return 1;
            else
                return 0;
        }
        
        if(dp[ind][t]!=-1)
            return dp[ind][t];
        
        int np=solve(ind-1,t,coins,dp);
        int p=0;
        if(coins[ind]<=t)
            p=solve(ind,t-coins[ind],coins,dp);
        
        return dp[ind][t]=p+np;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        return ans;
    }
};
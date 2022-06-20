class Solution {
public:
//     int solve(int ind, int t, vector<int>&a, vector<vector<int>>&dp)
//     {
//         if(ind==0)
//         {
//             if(t%a[0]==0)
//                 return t/a[0];
//             else INT_MAX-1;
//         }
        
//         if(dp[ind][t]!=-2)
//             return dp[ind][t];
        
//         int np=0;
//         if(ind-1>=0)
//             np+=solve(ind-1, t, a, dp);
//         else
//             np+=INT_MAX-1;
//         int p=INT_MAX-1;
//         if(a[ind]<=t)
//             p=1+solve(ind, t-a[ind], a, dp);
        
//         return dp[ind][t]=min(p,np);
//    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)
                dp[0][t]=t/coins[0];
            else
                dp[0][t]=INT_MAX-1;
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                int np=0;
                np+=dp[ind-1][t];
                int p=INT_MAX-1;
                if(coins[ind]<=t)
                    p=1+dp[ind][t-coins[ind]];

                dp[ind][t]=min(p,np);
            }
        }
        
        return (dp[n-1][amount]>=INT_MAX-1) ? -1 : dp[n-1][amount] ;
    }
};
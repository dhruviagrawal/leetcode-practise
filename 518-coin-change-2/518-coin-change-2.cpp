class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(!n)
            return 0;
        if(!amount)
            return 1;
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int t=0;t<=amount;t++)
        {
                dp[0][t]=(t%coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                int np=dp[ind-1][t];
                int p=0;
                if(coins[ind]<=t)
                    p=dp[ind][t-coins[ind]];

                dp[ind][t]=p+np;
            }
        }
        
        return dp[n-1][amount];
    }
};
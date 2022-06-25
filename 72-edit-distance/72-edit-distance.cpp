class Solution {
public:
    int solve(int i, int j, string &w1, string &w2, vector<vector<int>>&dp)
    {
        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(w1[i-1]==w2[j-1])
            return dp[i][j]=solve(i-1,j-1,w1,w2,dp);
        
        int ins=1+solve(i,j-1,w1,w2,dp);
        int dlt=1+solve(i-1,j,w1,w2,dp);
        int rep=1+solve(i-1,j-1,w1,w2,dp);
        
        return dp[i][j]=min(ins, min(dlt,rep));
    }
    int minDistance(string w1, string w2) {
        int n=w1.size(), m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=solve(n, m, w1, w2,dp);
        return ans;
    }
};
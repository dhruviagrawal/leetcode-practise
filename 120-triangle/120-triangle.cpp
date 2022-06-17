class Solution {
public:
    int solve(int i,int j, vector<vector<int>>&a, int n, vector<vector<int>>&dp)
    {
        if(i==(n-1))
            return a[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int d=a[i][j]+solve(i+1,j,a,n,dp);
        int dg=a[i][j]+solve(i+1,j+1,a,n,dp);
        
        return dp[i][j]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=solve(0,0,a,n,dp);
        return ans;
    }
};
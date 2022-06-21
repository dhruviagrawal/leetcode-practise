class Solution {
public:
    int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>>&dp)
    {
        if(ind1==0 || ind2==0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(s1[ind1-1]==s2[ind2-1])
            return dp[ind1][ind2]=1+solve(ind1-1, ind2-1, s1, s2, dp);
        
        return dp[ind1][ind2]=max(solve(ind1-1, ind2, s1, s2, dp), solve(ind1, ind2-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        // int ans=solve(n,m,s1,s2,dp);
        // return ans;
        
        for(int i=0;i<=n;i++)
            prev[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    curr[j]=1+prev[j-1];
                else
                    curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        
        return prev[m];
    }
};
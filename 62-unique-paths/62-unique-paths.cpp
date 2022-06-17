class Solution {
public:
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        //int ans;
        //solve(m-1,n-1,dp);
        vector<int>prevRow(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>currRow(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    currRow[j]=1;
                else
                {
                    int up=0,left=0;
                    if(i>0) up=prevRow[j];
                    if(j>0) left=currRow[j-1];
                    currRow[j]=up+left;
                }
            }
            prevRow=currRow;
        }
        return prevRow[n-1];
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        
        vector<int>nextRow(n,0);
        
        for(int j=0;j<n;j++)
            nextRow[j]=a[n-1][j];
        
        for(int i=n-2;i>=0;i--)
        {
            vector<int>currRow(n,0);
            for(int j=i;j>=0;j--)
            {
                int d=a[i][j]+nextRow[j];
                int dg=a[i][j]+nextRow[j+1];
                currRow[j]=min(d,dg);
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
};
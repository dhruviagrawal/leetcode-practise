class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int>prevRow(m,0);
        for(int j=0;j<m;j++)
        {
            prevRow[j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            vector<int>currRow(m,0);
            for(int j=0;j<m;j++)
            {
                int s=matrix[i][j];  
                s+=prevRow[j];
                int ld=matrix[i][j];
                if(j-1>=0) ld+=prevRow[j-1];
                else ld+=1e9;
                int rd=matrix[i][j];
                if(j+1<m) rd+=prevRow[j+1];
                else rd+=1e9;
                
                currRow[j]=min(s,min(rd,ld));
            }
            prevRow=currRow;
        }
        
        int ans=1e9;
        for(int j=0;j<m;j++)
        {
            ans=min(ans,prevRow[j]);
        }
        return ans;
    }
};
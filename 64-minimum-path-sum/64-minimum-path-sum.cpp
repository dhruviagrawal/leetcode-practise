class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //vector<vector<int>>dp(n,vector<int>(m,0));
        
        vector<int>prevRow(m,0);
    for(int i=0; i<n ; i++){
        vector<int>currRow(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) currRow[j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += prevRow[j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=currRow[j-1];
                else left += 1e9;
                
                currRow[j] = min(up,left);
            }
        }
         prevRow=currRow;
    }
    
    return prevRow[m-1];
    }
    
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        
        if(n*m != r*c)
            return mat;
        vector<vector<int>>ans(r, vector<int>(c,-1));
        
        for(int i=0;i<(r*c);i++)
        {
            ans[i/c][i%c]=mat[i/n][i%n];
        }
       
        return ans;
    }
};
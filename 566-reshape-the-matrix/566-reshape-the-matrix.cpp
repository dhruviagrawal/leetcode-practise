class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        
        if(n*m != r*c)
            return mat;
        vector<vector<int>>ans(r, vector<int>(c,-1));
        
        
        /*
           i/c will give us the row number of output matrix. 
           We will move to New row after every c elements 
           and thus dividing by c will give the row number

           i%c will give us the column number of output matrix. 
           We will be begin from start of new row after every c elements 
           and this the remainder will give column of current row.

           The same happens in i/n and i%n but for the mat matrix
        */
        
        for(int i=0;i<(r*c);i++)
        {
            ans[i/c][i%c]=mat[i/n][i%n];
        }
       
        return ans;
    }
};
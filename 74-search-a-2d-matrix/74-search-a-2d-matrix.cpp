class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        
        int lo=0, hi=n*m-1;
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            
            int x=matrix[mid/m][mid%m];
            if(x==target)
                return true;
            else if(x>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return false;
    }
};
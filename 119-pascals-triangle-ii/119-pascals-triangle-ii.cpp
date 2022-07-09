class Solution {
public:
    long long int ncr(int n, int r)
    {
       long long int ans=1;
       
        for(int i=1;i<=r;i++)
        {
            ans*=(n-i+1);
            ans/=i;
        }
        return ans;
    }
    vector<int> getRow(int n) {
        vector<int>ans;
        
       int i=n;
        
        for(int j=0;j<=i;j++)
        {
            ans.push_back(ncr(i,j));
        }
        
        return ans;
    }
};
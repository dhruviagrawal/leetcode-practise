class Solution {
public:
    int setbits(int n)
    {
        int c=0;
        while(n)
        {
            n=n&(n-1);
            c++;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            ans[i]=setbits(i);
        }
        return ans;
    }
};
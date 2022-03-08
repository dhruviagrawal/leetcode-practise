class Solution {
public:
    int countOrders(int n) {
        long ans=1;
        long mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            ans%=mod;
            ans*=(2*i-1);
            ans%=mod;
        }
        return ans;
    }
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int>freq(n,0);
        for(int x:nums)
            freq[x]+=x;
        
        vector<int>dp(n,0);
        dp[0]=freq[0];
        dp[1]=max(freq[0],freq[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(freq[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};
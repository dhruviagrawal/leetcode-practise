class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxp=0, mini=prices[0];
        for(int i=1;i<n;i++)
        {
            maxp=max(maxp, prices[i]-mini);
            mini=min(mini, prices[i]);
        }
        return maxp;
    }
};
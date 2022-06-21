class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<int>prev(amount+1,0),curr(amount+1,0);

        for(int t=0;t<=amount;t++)
        {
                prev[t]=(t%coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                int np=prev[t];
                int p=0;
                if(coins[ind]<=t)
                    p=curr[t-coins[ind]];

                curr[t]=p+np;
            }
            prev=curr;
        }
        
        return prev[amount];
    }
};
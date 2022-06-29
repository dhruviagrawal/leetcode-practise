class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>next(2,0),curr(2,0);
       
        //next[0]=next[1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                int maxp=0;
                if(b)
                {
                    int b=-prices[i]+next[0];
                    int nb=next[1];
                    maxp=max(b,nb);
                }
                else
                {
                    int s=prices[i]-fee+next[1];
                    int ns=next[0];
                    maxp=max(s,ns);
                }
                curr[b]=maxp;
            }
            next=curr;
        }
        
        return next[1];
    }
};
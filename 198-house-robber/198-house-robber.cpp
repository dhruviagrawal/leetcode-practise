class Solution {
public: 
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int>dp(n,-1);
        int neg=0;
        //dp[0]=nums[0];
        int prev,prev2,curr;
        prev=nums[0];
        prev2=0;
        
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=prev;
            
            curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
            
        }
        return prev;
    }
};
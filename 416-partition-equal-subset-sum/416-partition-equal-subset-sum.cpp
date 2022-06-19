class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
       
        for(int x:nums)
            s+=x;
        if(s%2!=0)
            return false;
        else
        {
            s=s/2;
            vector<vector<bool>>dp(n,vector<bool>(s+1,0));
            for(int ind=0;ind<n;ind++)
                dp[ind][0]=true;
            if(nums[0]<=s)
                dp[0][nums[0]]=true;
            
            for(int ind=1;ind<n;ind++)
            {
                for(int target=1;target<=s;target++)
                {
                    bool notpick=dp[ind-1][target];
        
                    bool pick=false;
                    if(nums[ind]<=target)
                        pick=dp[ind-1][target-nums[ind]];

                    dp[ind][target]=pick | notpick;
                }
            }
            
            return dp[n-1][s];
        }
    }
};
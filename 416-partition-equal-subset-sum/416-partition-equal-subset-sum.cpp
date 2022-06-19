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
            vector<bool>prev(s+1,0),curr(s+1,0);
            prev[0]=curr[0]=true;
            
            for(int ind=1;ind<n;ind++)
            {
                for(int target=1;target<=s;target++)
                {
                    bool notpick=prev[target];
        
                    bool pick=false;
                    if(nums[ind]<=target)
                        pick=prev[target-nums[ind]];

                    curr[target]=pick | notpick;
                }
                prev=curr;
            }
            
            return prev[s];
        }
    }
};
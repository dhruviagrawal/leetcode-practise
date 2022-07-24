class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
        int maxs=INT_MIN, s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            maxs=max(maxs,s);
            
            if(s<0)
                s=0;
        }
        
        return maxs;
    }
};
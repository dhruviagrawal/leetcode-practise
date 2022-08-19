class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int lo=0, hi=n-1;
        
        while(lo+1<n && nums[lo]<=nums[lo+1]) lo++;
        while(hi-1>=0 && nums[hi]>=nums[hi-1]) hi--;
        
        if(lo==n-1)
            return 0;
        
        int maxi=INT_MIN, mini=INT_MAX;
        
        for(int i=lo;i<=hi;i++)
        {
            maxi=max(maxi, nums[i]);
            mini=min(mini, nums[i]);
        }
        
        while(lo-1>=0 && nums[lo-1]>mini) lo--;
        while(hi+1<n && nums[hi+1]<maxi) hi++;
        
        return hi-lo+1;
    }
};
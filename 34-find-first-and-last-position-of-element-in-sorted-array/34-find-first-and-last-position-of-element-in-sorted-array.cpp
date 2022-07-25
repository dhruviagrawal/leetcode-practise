class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        
        vector<int>ans(2,-1);
        //first occ
        int lo=0,hi=n-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            {
                ans[0]=mid;
                hi=mid-1;
            }
            else if(nums[mid]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        
        
        //last occ
        lo=0, hi=n-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            {
                ans[1]=mid;
                lo=mid+1;
            }
            else if(nums[mid]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        
       
        return ans;
        
    }
};
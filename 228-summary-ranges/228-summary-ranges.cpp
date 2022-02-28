class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        
        vector<string>ans;
        if(n==0) return ans;
        
        int lo=nums[0],hi=nums[0];
        for(int i=0;i<n;)
        {
            int lo=i,hi=i;
            while(hi+1<n && nums[hi+1]==nums[hi]+1)
                hi++;
            if(hi==lo)
                ans.push_back(to_string(nums[lo]));
            else
                ans.push_back(to_string(nums[lo])+"->"+to_string(nums[hi]));
            i=hi+1;
        }
        return ans;
    }
};
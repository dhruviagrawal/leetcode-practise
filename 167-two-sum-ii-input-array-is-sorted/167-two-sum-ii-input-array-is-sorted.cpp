class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        vector<int>ans;
        while(lo<hi)
        {
            int s=nums[lo]+nums[hi];
            
            if(s==target)
            {
                ans.push_back(lo+1);
                ans.push_back(hi+1);
                break;
            }
            else if(s<target)
                lo++;
            else
                hi--;
        }
        return ans;
    }
};
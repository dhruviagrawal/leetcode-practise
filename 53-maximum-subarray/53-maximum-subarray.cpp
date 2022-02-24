class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, maxsum=nums[0];
        for(int n:nums)
        {
            sum+=n;
            maxsum=max(sum,maxsum);
            if(sum<0) sum=0;
        }
        return maxsum;
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0;
        int v[n];
        for(int i=0;i<n;i++) v[i]=0;
        for(int i=2;i<n;i++)
        {
            if((nums[i]-nums[i-1])==(nums[i-1]-nums[i-2]))
            {
                v[i]=v[i-1]+1;
                ans+=v[i];
            }
        }
        return ans;
    }
};
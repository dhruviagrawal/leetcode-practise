class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xorsum=0;
        for(int i=0;i<n;i++)
            xorsum=xorsum^nums[i];
        return xorsum;
    }
};
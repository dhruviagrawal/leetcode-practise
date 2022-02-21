class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        // return nums[n/2];
        
        unordered_map<int,int>mp;
        for(int a:nums)
            mp[a]++;
        for(auto b:mp)
        {
            if(b.second>n/2)
                return b.first;
        }
        return 0;
    }
};
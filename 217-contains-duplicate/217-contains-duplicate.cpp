class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int x:nums)
        {
            if(mp.find(x)!=mp.end())
                return true;
            else mp[x]++;
        }
        return false;
    }
};
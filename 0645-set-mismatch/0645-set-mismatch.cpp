class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int x:nums)
        {
            mp[x]++;
            if(mp[x]==2)
                ans.push_back(x);
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    void func(int ind, vector<int>& ds, int sum, vector<int>& candidates, int target, vector<vector<int>>&ans)
    {
        int n=candidates.size();
        if(ind>=n)
            return;
        
        ds.push_back(candidates[ind]);
        sum+=candidates[ind];
        if(sum<target)
            func(ind, ds, sum, candidates, target, ans);
        if(sum==target)
            ans.push_back(ds);
        sum-=candidates[ind];
        ds.pop_back();
        func(ind+1, ds, sum, candidates, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        func(0, ds, 0, candidates, target, ans);
        return ans;
    }
};
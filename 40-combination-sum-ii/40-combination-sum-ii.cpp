class Solution {
public:
    void func(int ind, vector<int>&ds, int target, vector<int>&candidates, vector<vector<int>>&ans)
    {
        int n=candidates.size();
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            if(i>ind && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            func(i+1, ds, target-candidates[i], candidates, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        func(0, ds, target, candidates, ans);
        return ans;
    }
};
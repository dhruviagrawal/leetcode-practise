class Solution {
public:
    void findCombination(int index, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>> &ans)
    {
        int n=candidates.size();
        if(index==n)
        {
            if(target==0) ans.push_back(ds);
            return;
        }
        //pick up element
        if(target>=candidates[index])
        {
            ds.push_back(candidates[index]);
            findCombination(index,target-candidates[index],candidates,ds,ans);
            ds.pop_back();
        }
        
        //don't pick element
        findCombination(index+1,target,candidates,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(0,target,candidates,ds,ans);
        return ans;
    }
};
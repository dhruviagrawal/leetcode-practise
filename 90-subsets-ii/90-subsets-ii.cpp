class Solution {
public:
    void f(int ind, vector<int>&a, vector<int>&ds, vector<vector<int>>&ans)
    {
        ans.push_back(ds);
        int n=a.size();
        for(int i=ind;i<n;i++)
        {
            if(i!=ind && a[i]==a[i-1])
                continue;
            
            ds.push_back(a[i]);
            f(i+1,a,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        f(0,nums,ds,ans);
        return ans;
    }
};
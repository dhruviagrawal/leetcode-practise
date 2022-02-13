class Solution {
public:
    //n elements, 2^n subsets!
    
    // Time complexity : O(N*(2^N))
    // Space complexity : O(N*(2^N))
    vector<vector<int>>ans;
    void generate(vector<int> &subset, int i, vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(subset);
            return;
        }
        generate(subset,i+1,nums); //ith element not in subset
        
        //ith element in subset
        subset.push_back(nums[i]);
        generate(subset,i+1,nums);
        subset.pop_back(); //backtracking 
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        generate(subset,0,nums);
        return ans;
    }
};
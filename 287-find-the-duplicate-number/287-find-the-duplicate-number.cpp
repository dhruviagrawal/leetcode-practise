class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n=nums.size();
        
//         for(int i=0;i<n-1;i++)
//         {
//             if(nums[i]==nums[i+1])
//                 return nums[i];
//         }
//         return -1;
        
        
        
        
//         unordered_map<int,int>mp;
//         for(int n:nums)
//         {
//             if(mp.find(n)!=mp.end())
//                 return n;
//             mp[n]++;
//         }
        
//         return -1;
        
        
        
        int slow=nums[0], fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        
        fast=nums[0];
        
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
    }
};
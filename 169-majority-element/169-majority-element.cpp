class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        int c=0,ele=0;
        for(int i=0;i<n;i++)
        {
            if(c==0)
                ele=nums[i];
            if(nums[i]==ele)
                c++;
            else
                c--;
        }
        
        return ele;
    }
};
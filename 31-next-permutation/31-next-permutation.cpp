class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }
        int i=nums.size()-1;
        i--;
        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }else{
            int index=i+1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[index]>nums[j] && nums[j]>nums[i]){
                    index=nums[index]<nums[j]?index:j;
                }
            }
            swap(nums[i],nums[index]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};
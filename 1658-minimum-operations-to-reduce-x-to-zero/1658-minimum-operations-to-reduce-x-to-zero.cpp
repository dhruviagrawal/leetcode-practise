class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        
        int s=0;
        for(int a:nums)
            s+=a;
        int rest=s-x; //this should be sum of left elements contiguous array
        
        //we need max length subarray with sum rest-sliding window
        
        int curr=0;
        int i=0;
        int maxlen=0;
        bool f=false;
        
        for(int j=0;j<n;j++)
        {
            curr+=nums[j];
            while(i<=j && curr>rest)
            {
                curr-=nums[i];
                i++;
            }
            if(curr==rest)
            {
                maxlen=max(maxlen,j-i+1);
                f=true;
            }
        }
        
        int ans;
        
        if(!f) ans=-1;
        else ans=n-maxlen;
        return ans;
    }
};
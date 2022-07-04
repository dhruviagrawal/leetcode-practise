class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>sum(n);
        
        sum[0]=nums[0];
        
        if(n==1)
            return 0; 
        
        if(n==2)
        {
            if(nums[1]==0)
                return 0;
            else if(nums[0]==0)
                return 1;
        }
        
        for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+nums[i];
        
        int l=0, r=sum[n-1]-sum[0];
        if(l==r)
            return 0;
        
        for(int i=1;i<n;i++)
        {
            int ls,rs;
            ls=sum[i-1];
            rs=sum[n-1]-sum[i];
            
            if(ls==rs)
                return i;
        }
        
        return -1;
    }
};
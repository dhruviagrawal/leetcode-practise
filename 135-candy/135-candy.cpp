class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        if(n<2)
            return n;
        
        int ans=0;
        vector<int>c(n,1);
        // for(int i=0;i<n;i++)
        // {
        //     if(i==0 && r[i+1]<r[i])
        //     {
        //         c[i]=c[i+1]+1;
        //     }
        //     else if(i==n-1 && r[i-1]<r[i])
        //     {
        //         c[i]=c[i-1]+1;
        //     }
        //     else if(i!=0 && i!=n-1)
        //     {
        //         if(r[i]>r[i+1] && r[i]>r[i-1])
        //             c[i]=max(r[i+1],r[i-1])+1;
        //         else if(r[i]>r[i-1])
        //             c[i]=r[i-1]+1;
        //         else if(r[i]>r[i+1])
        //             c[i]=r[i+1]+1;
        //         else 
        //             continue;
        //     }
        //     else 
        //         continue;
        // }
        
        for(int i=1;i<n;i++)
        {
            if(r[i]>r[i-1] && c[i]<=c[i-1])
                c[i]=c[i-1]+1;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(r[i]>r[i+1] && c[i]<=c[i+1])
                c[i]=c[i+1]+1;
        }
        
        for(int i=0;i<n;i++)
            ans+=c[i];
        
        return ans;
    }
};
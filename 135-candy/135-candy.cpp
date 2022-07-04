class Solution {
public:
    int sumf(int n) {
        return (n * (n + 1)) / 2;
    }
    int candy(vector<int>& r) {
//         int n=r.size();
//         if(n<2)
//             return n;
        
//         int ans=0;
//         vector<int>c(n,1);
        
//         for(int i=1;i<n;i++)
//         {
//             if(r[i]>r[i-1] && c[i]<=c[i-1])
//                 c[i]=c[i-1]+1;
//         }
        
//         for(int i=n-2;i>=0;i--)
//         {
//             if(r[i]>r[i+1] && c[i]<=c[i+1])
//                 c[i]=c[i+1]+1;
//         }
        
//         for(int i=0;i<n;i++)
//             ans+=c[i];
        
//         return ans;
        
        int n=r.size();
        if(n <= 1) return n;
        int candies = 0;
        int up = 0, down = 0; 
        int prevSlope = 0;
        
        for(int i = 1; i < n; i++) {
            //If increasing then 1; if decreasing then -1; if equal then 0.
            int currSlope = (r[i] > r[i-1]) ? 1 
                : (r[i] < r[i-1] ? -1 : 0);
            //                                       _
            //If mountain is changing. \_ or \/ or  /
            if((prevSlope < 0 && currSlope >= 0) || (prevSlope > 0 && currSlope == 0)) {  
                candies = candies + sumf(up) + sumf(down) + (max(up, down));
                //System.out.println(up + " "+ down + " " +candies);
                up = 0; 
                down = 0;
            }
            
            //Add in up/down if slope is increasing or decreasing respectively. 
            //If it is a plain, add a candy as it is the base case.
            if(currSlope > 0) {
                up++;
            }
            else if(currSlope < 0) {
                down++;
            }
            else {
                candies++;
            }
            
            prevSlope = currSlope;
        } 
        //System.out.println(up + " "+ down + " "+ candies);
        candies = candies + sumf(up) + sumf(down) + max(up, down) + 1;
        return candies;
    }
    
    int sum(int n) {
        return (n * (n + 1)) / 2;
    }
};
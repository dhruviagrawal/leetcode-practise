class Solution {
public:
    int countOdds(int lo, int hi) {
        int d;
        if(lo%2!=0 && hi%2!=0)
        {
            d=(hi-1)-(lo+1);
            d/=2;
            return d+2;
        }
        else 
        {
            d=hi-lo;
        }
        if(d%2==0)
            return d/2;
        else
            return 1+d/2;
        
    }
};
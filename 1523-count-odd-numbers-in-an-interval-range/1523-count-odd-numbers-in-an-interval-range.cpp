class Solution {
public:
    int countOdds(int low, int high) {
        int d=high-low;
        d/=2;
        if(low%2!=0 || high%2!=0)
            d++;
        return d;
    }
};
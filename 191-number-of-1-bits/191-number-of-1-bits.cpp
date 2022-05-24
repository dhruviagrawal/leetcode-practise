class Solution {
public:
    int hammingWeight(uint32_t n) {
        //no. of set bits==no. of iterations.
        int c=0;
        while(n)
        {
            c++;
            n=n&(n-1); //making rightmost set bit to 0
        }
        return c;
    }
};
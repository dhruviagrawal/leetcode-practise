class Solution {
public:
    int subtractProductAndSum(int n) {
        int ans;
        int s=0,p=1;
        while(n)
        {
            int d=n%10;
            s+=d;
            p*=d;
            n/=10;
        }
        ans = p-s;
        return ans;
    }
};
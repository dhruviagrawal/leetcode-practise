class Solution {
public:
    double average(vector<int>& salary) {
        double ans;
        int n=salary.size();
        double s=0;
        int mins=salary[0], maxs=salary[0];
        for(int x:salary)
        {
            s+=(double)x;
            mins=min(mins,x);
            maxs=max(maxs,x);
        }
        s-=mins;
        s-=maxs;
        ans=s/(n-2)*1.0;
        return ans;
    }
};
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int c=-1,d=-1,ans=0;
        sort(intervals.begin(),intervals.end());
        for(auto v:intervals)
        {
            if(v[0]>c && v[1]>d)
            {
                c=v[0];
                ans++;
            }
            d=max(d,v[1]);
        }
        return ans;
    }
};
class Solution {
public:
    static bool comp(vector<int>&b1, vector<int>&b2)
    {
        return b1[1]>b2[1]; //sorts desc order acc to units per box
    }
    int maximumUnits(vector<vector<int>>&a, int w) {
        int n=a.size();
        sort(a.begin(), a.end(), comp);
        int ans=0;;
        for(auto it:a)
        {
            if(it[0]<=w)
            {
                w-=it[0];
                ans+=(it[0]*it[1]);
            }
            else
            {
                ans+=(it[1]*w);
                w=0;
            }
        }
        return ans;
    }
};
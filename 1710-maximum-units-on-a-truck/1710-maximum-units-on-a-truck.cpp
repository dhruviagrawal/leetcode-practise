class Solution {
public:
    // static bool comp(vector<int>&b1, vector<int>&b2)
    // {
    //     return b1[1]>b2[1]; //sorts desc order acc to units per box
    // }
    // int maximumUnits(vector<vector<int>>&a, int w) {
    //     int n=a.size();
    //     sort(a.begin(), a.end(), comp);
    //     int ans=0;;
    //     for(auto it:a)
    //     {
    //         if(it[0]<=w)
    //         {
    //             w-=it[0];
    //             ans+=(it[0]*it[1]);
    //         }
    //         else
    //         {
    //             ans+=(it[1]*w);
    //             w=0;
    //         }
    //     }
    //     return ans;
    // }
    
    //linear complexity
    int maximumUnits(vector<vector<int>>&a, int w)
    {
        vector<int>sortedboxtypes(1001,0);
        for(auto it:a)
        {
            sortedboxtypes[it[1]]+=it[0];
        }
        int ans=0;
        for(int i=1000; i>=0; i--)
        {
            if(sortedboxtypes[i]<=w)
            {
                w-=sortedboxtypes[i];
                ans+=(sortedboxtypes[i]*i);
            }
            else
            {
                ans+=(w*i);
                w=0;
            }
        }
        
        return ans;
    }
};
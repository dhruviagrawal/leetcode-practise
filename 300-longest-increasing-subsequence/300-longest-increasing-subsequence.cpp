class Solution {
public: 
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        int len=1;
        vector<int>t;
        t.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>t.back())
            {
                t.push_back(a[i]);
                len++;
            }
            else
            {
                int ind=lower_bound(t.begin(), t.end(), a[i])-t.begin();
                t[ind]=a[i];
            }
        }
        return len;
    }
};
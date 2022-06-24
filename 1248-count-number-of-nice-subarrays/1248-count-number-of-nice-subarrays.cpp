class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int b) {
        int n=a.size();
        unordered_map<int,int>mp;
       
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0)
                a[i]=0;
            else a[i]=1;
        }
        int s=0,c=0,i;
        for(i=0;i<n;i++)
        {
            s+=a[i];
            if(s==b)
                c++;
            if(mp.find(s-b)!=mp.end())
                c+=mp[s-b];
            mp[s]++;
        }
        return c;
    }
};
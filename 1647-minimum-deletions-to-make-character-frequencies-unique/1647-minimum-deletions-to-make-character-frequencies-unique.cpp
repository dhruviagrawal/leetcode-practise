class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int>v(26,0);
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
        }
        
        sort(v.begin(), v.end(), greater<int>());
        int ans=0, maxi=v[0];
        
        for(int a:v)
        {
            if(a>maxi)
            {
               if(maxi>0) ans+=(a-maxi);
               else  ans+=a;
            }
            
            maxi=min(maxi-1, a-1);
        }
        
        return ans;
    }
};
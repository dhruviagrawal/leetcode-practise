class Solution {
public:
    bool canConstruct(string s, string t) {
        int n=s.size(), m=t.size();
        
        if(n>m)
            return false;
        
        unordered_map<char,int>mp;
        for(char c:t)
            mp[c]++;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])==mp.end())
                return false;
            else if(mp[s[i]]<1)
                return false;
            else
            {
                mp[s[i]]--;
                s[i]='#';
            }
        }
        
        for(int i=0;i<n;i++)
            if(s[i]!='#')
                return false;
        
        return true;
    }
};
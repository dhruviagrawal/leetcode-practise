class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        
        int c=0, odd=0, f=-1;
        
        if(mp.size()==1)
            return n;
        
        for(auto it:mp)
        {
            if(it.second%2==0)
                c+=it.second;
            else
            {
              if(f==-1)
              {
                  f=0;
                  odd=1;
              }
                c+=(it.second-1);
            }
        }
        
        
        if(odd>0) 
           c++;
        
        return c;
    }
};
class Solution {
public:
    int lcs(string s1, string s2) {
        int n=s1.size();
        
        vector<int>prev(n+1,0),curr(n+1,0);
        
        for(int i=0;i<=n;i++)
            prev[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    curr[j]=1+prev[j-1];
                else
                    curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        
        return prev[n];
    }
    string rev(string s)
    {
        string st="";
        for(int i=s.size()-1;i>=0;i--)
            st+=s[i];
        return st;
    }
    int longestPalindromeSubseq(string s) {
        int ans=lcs(s,rev(s));
        return ans;
    }
};
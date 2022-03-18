class Solution {
public:
   // TC O(N) SC O(N)
    string removeDuplicateLetters(string s) {
        int n=s.size();
        
        stack<char>st;
        vector<int>lastindex(26,0);
        vector<bool>seen(26,false);
        
        for(int i=0;i<n;i++)
            lastindex[s[i]-'a']=i;
            
        for(int i=0;i<n;i++)
        {
            int curr=s[i]-'a';
            if(seen[curr])
                continue;
            while(!st.empty() && st.top()>s[i] && i<lastindex[st.top()-'a'])
            {
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr]=true;
        }
        
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
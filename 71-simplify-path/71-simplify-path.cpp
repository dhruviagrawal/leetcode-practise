class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
    stack<string>st;
    for(int i=0;i<n;i++)
    {
        if(path[i]=='/')
        continue;
        
        string t="";
        
        while(i<n && path[i]!='/')
        {
            t+=path[i];
            i++;
        }
        
        if(t=="..")
        {
            if(!st.empty())
            st.pop();
        }
        else if(t==".")
        continue;
        else
        {
            st.push(t);
        }
    }
    
    string ans="";
    while(!st.empty())
    {
        ans="/"+st.top()+ans;
        st.pop();
    }
    
    if(ans.size()==0)
    return "/";
    
    return ans;
    }
};
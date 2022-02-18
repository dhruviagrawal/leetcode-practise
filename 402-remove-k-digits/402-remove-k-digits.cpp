class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k >= num.size()) return "0"; //all letters removed
        
        stack<char>st;
        int n=num.size();
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                st.push(num[i]);  //push if stack empty
            else
            {
                //find first appearing large numbers n remove them 
                char ele=num[i];
                while(!st.empty() && st.top()>ele && k)
                {
                    st.pop();
                    k--;
                   
                }
                 st.push(ele);
            }
        }
        
        //if still k left remove digits
        while(k>0)
        {
            st.pop();
            k--;
        }
        
        if(st.empty()) return "0"; //all letters removed
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top(); //stack now has string
            st.pop();
        }
        
        reverse(ans.begin(),ans.end()); // could have done ans=st.top()+ans directly too!
        
        //avoid leading zeroes
        int i=0;
        while(ans[i]=='0')
            i++;
    
        return (ans.substr(i)=="") ? "0" : ans.substr(i); 
    }
};
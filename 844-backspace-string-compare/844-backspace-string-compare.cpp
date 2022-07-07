class Solution {
public:
    bool backspaceCompare(string s, string t) {
       
        stack<char>st1;
        stack<char>st2;
        
        for(char c:s)
        {
            if(c!='#')
                st1.push(c);
            else if(!st1.empty())
                st1.pop();
        }
        
        for(char c:t)
        {
            if(c!='#')
                st2.push(c);
            else if(!st2.empty())
                st2.pop();
        }
        
        string a1="", a2="";
        
        while(!st1.empty())
        {
            a1+=st1.top();
            st1.pop();
        }
        reverse(a1.begin(), a1.end());
        
        while(!st2.empty())
        {
            a2+=st2.top();
            st2.pop();
        }
        reverse(a2.begin(), a2.end());
        if(a1==a2)
            return true;
        else
            return false;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        /*
        SC O(N)
        
        int n=s.size();
        stack<int>st;
        int score=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(score);
                score=0;
            }
            else
            {
                score=st.top()+max(2*score,1);
                st.pop();
            }
        }
        return score;
        */
        
        // O(1) space
        int depth=0,score=0;
        char prev='(';
        for(char c:s)
        {
            if(c=='(')
            {
                depth++;
            }
            else
            {
                depth--;
                if(prev=='(')
                    score+=pow(2,depth);
            }
            prev=c;
        }
        return score;
    }
};
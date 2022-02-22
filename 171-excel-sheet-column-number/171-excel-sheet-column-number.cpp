class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        
        for(char c:s)
        {
            int d=c-'A'+1;
            ans=ans*26+d;
        }
        return ans;
    }
};
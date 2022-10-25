class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a="",b="";
        for(string s:word1)
            a=a+s;
        for(string s:word2)
            b=b+s;
        
        if(a==b)
            return true;
        else
            return false;
    }
};
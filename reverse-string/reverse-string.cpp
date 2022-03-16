class Solution {
public:
    void rev(int left, int right, vector<char>& s)
    {
        if(left>right)
            return;
        swap(s[left],s[right]);
        rev(left+1, right-1, s);
    }
    void reverseString(vector<char>& s) {
       int left=0,right=s.size()-1;
       rev(left,right,s);
    }
};
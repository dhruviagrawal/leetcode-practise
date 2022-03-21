class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastOcc; //stores last occurence of each character
        vector<int>ans;
        for(int i=0;i<s.size();i++)
            lastOcc[s[i]]=i;
        int startIndex=0, lastIndex=0;
        for(int i=0;i<s.size();i++)
        {
            lastIndex=max(lastIndex, lastOcc[s[i]]);
            if(lastIndex==i)//start and last inex colliding!
            {
                ans.push_back(lastIndex-startIndex+1);
                startIndex=i+1;
            }
        }
        return ans;
    }
};
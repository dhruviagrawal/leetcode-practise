class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        int n=n1.size();
        int m=n2.size();
        set<int>ans;
          vector<int>res;
        if(n==0 || m==0)
            return res;
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        
        int i=0, j=0;
        
        while(i<n && j<m)
        {
            if(n1[i]==n2[j])
            {
                ans.insert(n1[i]);
                i++;
                j++;
            }
            else if(n1[i]>n2[j])
                j++;
            else
                i++;
        }
        
      
        for(auto it:ans)
        {
            res.push_back(it);
        }
        
        return res;
    }
};
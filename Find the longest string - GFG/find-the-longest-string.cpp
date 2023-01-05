//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool IsPresent(string str,unordered_map<string,int>&mm){
        string temp="";
        for(int i=0;i<str.length();i++){
            temp+=str[i];
            if(!mm[temp])return false;
        }
        return true;
    }
    string longestString(vector<string> &words)
    {
        // code here
        string ans="";
        unordered_map<string,int> mm;
        for(string x:words)mm[x]++;
        for(string x:words){
            if(IsPresent(x,mm)){
                if(x.length()>ans.length())ans=x;
                else if(x.length()==ans.length())ans=min(ans,x);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends
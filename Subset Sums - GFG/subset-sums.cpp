// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    
public:
    void f(int i, int s, vector<int>&a, int n, vector<int>&ans)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        f(i+1, s+a[i], a, n, ans);
        f(i+1, s, a, n, ans);
    }
public:
    vector<int> subsetSums(vector<int> a, int n)
    {
        // Write Your Code here
        
        vector<int>ans;
        f(0,0,a,n,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
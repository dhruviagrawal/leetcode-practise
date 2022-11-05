//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int a[], int n, int k) {
        // code here
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        mp[a[i]%k]++;
        
        int sz=0;
        for(int i=1;i<=(k/2);i++)
        {
            if(i!=k-i)
            sz+=max(mp[i],mp[k-i]);
            else
            {
                if(mp[i]) 
                sz++;
            }
        }
        if(mp[0]) sz++;
        
        return sz;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
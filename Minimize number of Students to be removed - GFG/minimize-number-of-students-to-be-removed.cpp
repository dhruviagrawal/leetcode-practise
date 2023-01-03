//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int n) {
        // code here
        vector<int>dp;
        for(int i=0;i<n;i++)
        {
            int x=h[i];
            auto it=lower_bound(dp.begin(), dp.end(), x);
            if(it==dp.end())
            dp.push_back(x);
            else
            *it=x;
        }
        return n-dp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
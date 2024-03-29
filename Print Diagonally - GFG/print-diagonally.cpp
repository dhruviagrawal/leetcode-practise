//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
		// Your code goes here
		vector<int>ans;
		int r=0, c=0;
		
		while(c<n)
		{
		    int i=r, j=c;
		    while(i<n && j>=0)
		    {
		        ans.push_back(a[i][j]);
		        i++;
		        j--;
		    }
		    c++;
		}
		
		c=n-1;
		r=1;
		while(r<n)
		{
		    int i=r, j=c;
		    while(i<n && j>=0)
		    {
		        ans.push_back(a[i][j]);
		        i++;
		        j--;
		    }
		    r++;
		}
		
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
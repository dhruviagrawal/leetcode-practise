//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define SIZE 10000
typedef struct
{
    string num;
    int move;
} NODE;


class Solution
{
  public:
    vector<int> prime;
    void sieve(void)
    {
	    int i, j;

        for (i = 0; i <= SIZE; i++) prime.push_back(1);
	    prime[0] = 0;
	    prime[1] = 0;
 
	    for (i = 4; i < SIZE; i =  i + 2)
	    {
		    prime[i] = 0;
	    }
 
	    for (i = 3; i * i <= SIZE; i = i + 2)
	    {
		    if (prime[i] == 0) continue;
		    for (j = (i * i); j < SIZE; j = j + (2 * i))
		    {
			    prime[j] = 0;
		    }
	    }
    }
    Solution()
    {
        // Every index of prime stores zero or one
        // If prime[i] is zero means i is not a prime
        // If prime[i] is one means i is a prime
        sieve();
    }
    int shortestPath(int Num1, int Num2)
    {
        int i, j, n, move, visit[SIZE];
        string str, num, nextNum;
        NODE node;
        queue<NODE> q;
        if (Num1 == Num2) return 0;
        memset(visit, 0, sizeof(visit));
        node.num  = to_string(Num1);
        node.move = 0;
        visit[Num1] = 1;
        q.push(node);
        for (   ;    ;   )
        {
            if (q.empty()) break;
            node = q.front();
            q.pop();
            num  = node.num;
            move = node.move;
            n = stoi(num);
            if (n == Num2) return move;
//printf("num %s, move %d\n", num.c_str(), move);
            for (i = 0; i < 4; i++)
            {
                nextNum = num;
                for (j = 0; j < 10; j++)
                {
                    if ((i == 0) && (j == 0)) continue;
                    nextNum[i] = j + '0';
                    n = stoi(nextNum);
//printf("i %d, j %d, nextNum %s, n %d\n", i, j, nextNum.c_str(), n);
                    if (prime[n] == 0) continue;
                    if (visit[n] == 1) continue;
                    visit[n] = 1;
                    node.num  = to_string(n);
                    node.move = move + 1;
                    q.push(node);
                }
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends
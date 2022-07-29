class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int c=0;
        if(a.empty())
            return 0;
        queue<pair<int,int>>q;
        int m=a.size(), n=a[0].size();
        int ans=0, tot=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=0)
                    tot++;
                if(a[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty())
        {
            int sz=q.size();
            c+=sz;
            for(int i=0;i<sz;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx<0 || ny<0 || nx>=m || ny>=n || a[nx][ny]!=1)
                        continue;
                    a[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            
            if(!q.empty())
                ans++;
        }
        
        
        return (tot==c)?ans:-1;
    }
};
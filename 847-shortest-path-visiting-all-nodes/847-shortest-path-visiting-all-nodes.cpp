class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int all=(1<<n)-1;
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++)
        {
            int mask=(1<<i);
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int val=node.first;
            int dist=node.second.first;
            int mask=node.second.second;
            for(auto neighbour:graph[val])
            {
                int newmask=(mask | (1<<neighbour)); //OR
                if(newmask==all)
                    return dist+1;
                else if(vis.count({neighbour,newmask}))
                    continue;
                else
                {
                    q.push({neighbour,{dist+1,newmask}});
                    vis.insert({neighbour,newmask});
                }
            }
        }
        return 0;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&par, TreeNode* target)
    {
        //bfs traversal to mark the parents-level order traversal happening
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
            {
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                par[node->right]=node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>par; //parent node store
        markParent(root, par, target);
        
        //now radially travel up, down left n right by 1 
        
        unordered_map<TreeNode*, bool>vis; //the node is visited or not
        
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        
        int dist=0;
        
        //2nd bfs to travel upto k dist from target
        
        while(!q.empty())
        {
            int sz=q.size();
            if(dist==k)
                break;
            else
                dist++;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(par[node] && !vis[par[node]])
                {
                    q.push(par[node]);
                    vis[par[node]]=true;
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};
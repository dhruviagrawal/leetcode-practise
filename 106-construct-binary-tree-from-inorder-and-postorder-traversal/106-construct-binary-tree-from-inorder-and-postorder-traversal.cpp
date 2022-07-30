/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      TreeNode* buildT(vector<int>&in, int instart, int inend, vector<int>&post, int poststart, int postend, map<int,int>&mp)
    {
        if((instart>inend) || (poststart>postend))
            return NULL;
        
        TreeNode* root=new TreeNode(post[postend]);
        int inroot=mp[post[postend]];
        int numsleft=inroot-instart;
        
        root->left=buildT(in, instart, inroot-1, post, poststart, poststart+numsleft-1, mp);
        root->right=buildT(in, inroot+1, inend, post, poststart+numsleft, postend-1, mp);
            
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size(), m=postorder.size();
        if(n!=m)
            return NULL;
        
        map<int,int>mp; //stores inorder
        
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        
        TreeNode* ans=buildT(inorder, 0, n-1, postorder, 0, m-1, mp);
        return ans;
    }
   
};
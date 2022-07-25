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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inmp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            inmp[inorder[i]]=i;
        }
        
        TreeNode* root=buildTree(preorder,0,n-1,inorder,0,n-1,inmp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>&preorder, int prestart, int preend, vector<int>&inorder, int instart, int inend, unordered_map<int,int>&inmp)
    {
        
        if(instart>inend || prestart>preend)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[prestart]);
        
        int inroot=inmp[root->val];
        int numsleft=inroot-instart;
        
        root->left=buildTree(preorder, prestart+1, prestart+numsleft, inorder, instart, inroot-1, inmp);
        
        root->right=buildTree(preorder, prestart+numsleft+1, preend, inorder, inroot+1, inend, inmp);
        
        return root;
    }
};
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
    TreeNode* kthsmallest(TreeNode* root,int &k)
    {
        if(root==NULL)
        return NULL;

        TreeNode* left=kthsmallest(root->left,k);
        if(left!=NULL)
        return left;
        k--;
        if(k==0)
        return root;

        return kthsmallest(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        root=kthsmallest(root,k);
        return root->val;
        
    }
};
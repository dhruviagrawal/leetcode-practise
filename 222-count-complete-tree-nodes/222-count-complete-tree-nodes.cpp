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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh=htleft(root);
        int rh=htright(root);
        
        if(lh==rh)
            return (1<<lh)-1; // pow(2,lh)-1 will be number of nodes
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int htleft(TreeNode* node)
    {
        int h=0;
        while(node)
        {
            h++;
            node=node->left;
        }
        return h;
    }
    
    int htright(TreeNode* node)
    {
        int h=0;
        while(node)
        {
            h++;
            node=node->right;
        }
        return h;
    }
};
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
    
    //Recursive
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
    void postorder(TreeNode* node, vector<int>&ans)
    {
        if(node==NULL)
            return ;
        
        postorder(node->left, ans);
        postorder(node->right, ans);
        
        ans.push_back(node->val);
    }
    
    
    //2 stacks
//    vector<int> postorderTraversal(TreeNode* root){ 
//     vector<int>ans;
//     if(root==NULL)
//         return ans;
//     stack<TreeNode*>st1,st2;
    
//     st1.push(root);
    
//     while(!st1.empty())
//     {
//         root=st1.top();
//         st1.pop();
//         st2.push(root);
//         if(root->left!=NULL) st1.push(root->left);
//         if(root->right!=NULL) st1.push(root->right);
//     }
    
//     while(!st2.empty())
//     {
//         ans.push_back(st2.top()->val);
//         st2.pop();
//     }
//     return ans;
//    }
    
    
    //only 1 stack
    //iska copy mein dekhlo algo 
};

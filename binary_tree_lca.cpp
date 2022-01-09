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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)    {
       if(root==NULL)
       {
           return NULL;
       }
        if(root==p || root==q)
        {
            return root;
        }
        TreeNode* leftr = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightr = lowestCommonAncestor(root->right,p,q);
        if(leftr!=NULL && rightr!=NULL)
        {
            return root;
        }
        else if(leftr!=NULL)
        {
            return leftr;
        }
        return rightr;
    }
};

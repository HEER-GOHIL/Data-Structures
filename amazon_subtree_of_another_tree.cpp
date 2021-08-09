/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * 
 */
class Solution {
public:
    bool issametree(TreeNode* t, TreeNode* subt)
    {
        if(!subt || !t)
        {
            return subt==NULL && t==NULL;
        }
        else if(subt->val == t->val)
        {
            return (issametree(t->left,subt->left) && issametree(t->right,subt->right));
        }
        else
        {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root)
        {
            return false;
        }
        else if(issametree(root,subRoot))
        {
            return true;
        }
        else
        {
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
            
    }
};

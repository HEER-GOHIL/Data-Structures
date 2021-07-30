class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return false;
        }
        else if(root->left==NULL && root->right==NULL && sum-root->val==0)
        {
            return true;
        }
        else
        {
            return (hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val));
        }
        return false;
    }
};

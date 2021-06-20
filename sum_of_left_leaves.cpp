class Solution
{
    public:
int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
    findsum(root,sum,false);
    return sum;
    }
    void findsum(TreeNode* root, int& sum,bool flag)
    {
        if(root==NULL)
        {
            return;
        }
        if(root && flag && root->left==NULL && root->right==NULL)
        {
            sum = sum + root->val;
        }
        findsum(root->left,sum,true);
        findsum(root->right,sum,false);
    }
};

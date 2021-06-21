class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        findgtree(root,sum);
        return root;
        
    }
    
    void findgtree(TreeNode* root, int& sum)
    {
        if(root==NULL)
        {
            return;
        }
        findgtree(root->right,sum);
        sum = sum + root->val;
        root->val = sum;
        findgtree(root->left,sum);
        
    }
};

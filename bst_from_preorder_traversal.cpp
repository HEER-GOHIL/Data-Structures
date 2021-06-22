class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder.front());
        for(int i=1;i<preorder.size();i++)
        {
            pretotree(root,preorder[i]);
        }
        return root;
        
    }
    void pretotree(TreeNode* root, int val)
    {
        if(root->val>val)
        {
            if(root->left)
            {
                pretotree(root->left,val);
            }
            else
            {
                root->left = new TreeNode(val);
            }
        }
        else if(root->val<val)
        {
            if(root->right)
            pretotree(root->right,val);
            else
            {
                root->right = new TreeNode(val);
            }
        }
        
    }

};

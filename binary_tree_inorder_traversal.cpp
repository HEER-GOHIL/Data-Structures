class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        Inorder(root,v);
        return v;
    }
    void Inorder(TreeNode* root,vector<int>& v)
    {
        if(root!=NULL)
        {
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
        }
        else 
        {
            return;
        }
    }
};

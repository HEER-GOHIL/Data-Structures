class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        vector<int>temp;
        findpaths(root,targetSum,temp,paths);
        return paths;
    }
    void findpaths(TreeNode* root, int sum, vector<int>curr,vector<vector<int>>& paths)
    {
        if(root==NULL)
        {
            return; 
        }
        if(root->val==sum && root->left==NULL && root->right==NULL)
        {
            curr.push_back(root->val);
            paths.push_back(curr);
        }
        curr.push_back(root->val);
        findpaths(root->left,sum-root->val, curr,paths);
        findpaths(root->right,sum-root->val, curr,paths);
    }
};

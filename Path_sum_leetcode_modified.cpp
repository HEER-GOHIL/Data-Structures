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
//
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return false;
        }
        stack<TreeNode*>stnode;
        stack<int>stsum;
        stnode.push(root);
        stsum.push(sum - root->val);
        while(!stnode.empty())
        {
            TreeNode* curr = stnode.top();
            stnode.pop();
            int curr_sum = stsum.top();
            stsum.pop();
            if(curr->left==NULL && curr->right==NULL && curr_sum==0)
            {
                return true;
            }
            if(curr->left!=NULL)
            {
                stnode.push(curr->left);
                stsum.push(curr_sum - curr->left->val);
            }
            if(curr->right!=NULL)
            {
                stnode.push(curr->right);
                stsum.push(curr_sum - curr->right->val);
            }
        }
        return false;
    }
};

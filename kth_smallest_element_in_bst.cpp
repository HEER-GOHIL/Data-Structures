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
    //helper
    void inorder(TreeNode* root, int *nums, int k)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,nums,k);
        if(++nums[0] == k)
        {
            nums[1] = root->val;
            return;
        }
        inorder(root->right,nums,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int nums[2] = {0,0};
        inorder(root,nums,k);
        return nums[1];
    }
};
//3-1-4-2
//inorder -> lowest to largest

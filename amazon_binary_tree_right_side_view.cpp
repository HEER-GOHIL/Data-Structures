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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>v;
        if(root==NULL)
        {
            return v;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            while(q.front()!=NULL)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(q.front()==NULL)
                {
                    v.push_back(temp->val);
                }
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            q.pop();
            if(!q.empty())
            {
            q.push(NULL);
            }
            
        }
        return v;
    }
};

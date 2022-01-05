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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL)
        {
            return -1;
        }
        set<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            q.pop();
            v.insert(curr->val);
        }
        if(v.size()<=1)
        {
            return -1;
        }
        set<int> :: iterator it;
        int count = 0;
         for(it=v.begin(); it != v.end();it++)
        {
            if(count==1)
            {
                return *it;
                break;
            }
            cout<<*it<<" ";
            cout<<endl;
            count ++;
        }
            return -1;
    }

};

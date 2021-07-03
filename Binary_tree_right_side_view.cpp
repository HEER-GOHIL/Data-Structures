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

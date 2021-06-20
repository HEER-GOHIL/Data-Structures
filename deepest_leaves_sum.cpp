class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return sum;
        }
        q.push(root);
        while(!q.empty())
        {
            sum = 0;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                sum = sum + temp->val;
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
            }            
        }
        return sum;
            
        
    }
};

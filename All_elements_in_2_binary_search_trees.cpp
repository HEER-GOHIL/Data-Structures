class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v; //to store all the elements
        queue<TreeNode*>q; //level order traversal;
        if(root1!=NULL)
        {
        q.push(root1); //level order traversal of root 1
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            v.push_back(temp->val); //push the node data
        }
        }
        // for second root
        if(root2!=NULL)
        {
        q.push(root2);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            v.push_back(temp->val); //push the node data
        }
        }
        sort(v.begin(), v.end(), greater<int>());
        reverse(v.begin(),v.end());
        return v;
    }
};

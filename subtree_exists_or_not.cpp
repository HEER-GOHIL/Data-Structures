class Solution {
public:
    bool issametree(TreeNode* t, TreeNode* subt)
    {
        if(!subt || !t) //if both are NULL then return true else if one of them is NULL return false
        {
            return subt==NULL && t==NULL;
        }
        else if(subt->val == t->val) // if the values are same check if the left and right subtree are also same 
        {
            return (issametree(t->left,subt->left) && issametree(t->right,subt->right));
        }
        else // exit case
        {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root) //if root is null return false
        {
            return false;
        }
        else if(issametree(root,subRoot)) // check if subtree and tree has same node
        {
            return true;
        }
        else
        {
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot); // else check in the left and right subtree 
        }
            
    }
};

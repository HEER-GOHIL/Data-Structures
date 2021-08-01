class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checktree(p,q);
        
    }
    bool checktree(TreeNode* t1, TreeNode* t2)
    {
        if(t1==NULL && t2==NULL)
        {
            return true;
        }
        else if ((t1==NULL && t2!=NULL) || (t1!=NULL && t2==NULL))
        {
            return false;
        }
        else if(t1->val!=t2->val)
        {
            return false;
        }
        return isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right);
        
    }
};

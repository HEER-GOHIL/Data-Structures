class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int d1 = finddepth(root,x);
        int d2 = finddepth(root,y);
        if(d1!=d2)
        {
            return false;
        }
        else
        {
            TreeNode* p1 = findparent(root,x);
            TreeNode* p2 = findparent(root,y);
            if(p1==p2)
            {
                return false;
            }
            else
            {
                return true;
            }
            
        }
    }
    //find depth
    int finddepth(TreeNode* root,int val)
    {
        if(root==NULL)
        {
            return INT_MIN;
        }
        if(root->val == val)
        {
            return 0;
        }
        return 1 + max(finddepth(root->left,val),finddepth(root->right,val));
    }
    //find parent 
    TreeNode* findparent(TreeNode* root, int val)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->left && root->left->val == val)
        {
            return root;
        }
        else if(root->right && root->right->val == val)
        {
            return root;
        }
        else if(root->val==val)
        {
            return root;
        }

            TreeNode* ltree = findparent(root->left,val);
            TreeNode* rtree = findparent(root->right,val);

       if(ltree!=NULL)
       {
           return ltree;
       }
        return rtree;
    }
    
};

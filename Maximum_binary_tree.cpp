class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()<0)
        {
            return NULL;
        }
        return createtree(nums.begin(),nums.end());
    }
    TreeNode* createtree(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end)
    {
        if(start>=end)
        {
            return NULL;
        }
        auto it = max_element(start,end); //max element in the array
        auto n = new TreeNode();
        n->val = *it;
        n->left = createtree(start,it);
        n->right = createtree(it+1,end);
        return n;
    }
};

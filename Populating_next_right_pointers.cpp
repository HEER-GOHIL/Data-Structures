class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q1;
        queue<Node*>q2;
        if(root==NULL)
        {
            return NULL;
        }
        if(root->left==NULL && root->right==NULL) //omly one node
        {
            return root;
        }
        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
            while(!q1.empty())
            {
                Node* temp = q1.front();
                q1.pop();
                if(!q1.empty())
                {
                    temp->next = q1.front();
                }
                else
                {
                    temp->next = NULL;
                }
                if(temp->left!=NULL)
                {
                    q2.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q2.push(temp->right);
                }
            }
            while(!q2.empty())
            {
                Node* temp = q2.front();
                q2.pop();
                if(!q2.empty())
                {
                    temp->next = q2.front();
                }
                else
                {
                    temp->next = NULL;
                }
                if(temp->left!=NULL)
                {
                    q1.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q1.push(temp->right);
                }
            }
            
        }
        return root;
    }
};

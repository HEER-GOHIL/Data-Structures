#include<bits/stdc++.h>
#include<stack>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int data;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void inorder(struct Node* root)
{
    stack<Node*>s;
    while(root!=NULL || !s.empty())
    {
        while(root!=NULL)
        {
        s.push(root);
        root = root->left;
        }
        root = s.top();
        s.pop();
        cout<<root->data<<" ";
        root = root->right;
    }
}
 
 int main()
 {
    struct Node* root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    inorder(root);
    return 0;
 }
 /*
          1
    2            3
4       5

 */

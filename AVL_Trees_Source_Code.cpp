#include <stdio.h>
#include <iostream>
using namespace std;
class Node 
{
  public:
  int data;
  Node* left;
  Node* right;
  int height;
};
//calculate height
int height(Node* N)
{
    if(N==NULL)
    {
        return 0;
    }
    return N->height;
}
//max function
int max(int a, int b)
{
    return(a>b) ? a : b;
}
//new node creation
Node *newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}
//rotate right
Node* rightrotate(Node* y)
{
    Node* x = y->left;
    Node* temp = x->right;
    y->left = temp;
    x->right = y;
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
//rotate left
Node* leftrotate(Node* x)
{
    Node* y = x->right;
    Node* temp = y->left;
    y->left = x;
    x->right = temp;
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}
//get the balance factor
int getbalancefactor(Node *N)
{
    if(N==NULL)
    {
        return 0;
    }
    return height(N->left) - height(N->right);
}
//Insert Node
Node* insertnode(Node *node, int data)
{
    if(node==NULL)
    {
        return (newNode(data));
    }
    if(data < node->data)
    {
        node->left = insertnode(node->left,data);
    }
    else if(data>node->data)
    {
        node->right = insertnode(node->right,data);
    }
    else
    {
        return node;
    }
    //update the balance factor of each node and balance the tree
    node->height = 1 + max(height(node->left),height(node->right));
    int bfactor = getbalancefactor(node);
    if(bfactor>1)
    {
        if(data<node->left->data)
        {
            return rightrotate(node);
        }
        else if(data>node->left->data)
        {
            node->left = leftrotate(node->left);
            return rightrotate(node);
        }
    }
    if(bfactor<-1)
    {
        if(data>node->right->data)
        {
            return leftrotate(node);
        }
        else if(data<node->right->data)
        {
            node->right = rightrotate(node->right);
            return leftrotate(node);
        }
    }
    return node;
}
//node with minimum value
Node* nodewithminval(Node* node)
{
    Node* curr = node;
    while(curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}
//delete a node
Node* delnode(Node* root, int data)
{
    if(root==NULL)
    {
        return root;
    }
    if(data<root->data)
    {
        root->left = delnode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right = delnode(root->right,data);
    }
    else
    {
        if(root->left==NULL || root->right==NULL)
        {
            Node* temp = NULL;
            if(root->left)
            {
                Node* temp = root->left;
            }
            else
            {
                Node* temp = root->right;
            }
            if(temp==NULL)
            {
                temp=root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            Node* temp = nodewithminval(root->right);
            root->data = temp->data;
            root->right = delnode(root->right,temp->data);
        }
    }
    if(root==NULL)
    {
        return root;
    }
    //update the bfactor of each nodewithminval
    root->height = 1 + max(height(root->left),height(root->right));
    int bfactor = getbalancefactor(root);
    if (bfactor > 1) {
    if (getbalancefactor(root->left) >= 0) {
      return rightrotate(root);
    } else {
      root->left = leftrotate(root->left);
      return rightrotate(root);
    }
  }
  if (bfactor < -1) {
    if (getbalancefactor(root->right) <= 0) {
      return leftrotate(root);
    } else {
      root->right = rightrotate(root->right);
      return leftrotate(root);
    }
  }
  return root;
    
}
// Print the tree
void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->data << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}
int main() {
  Node *root = NULL;
  root = insertnode(root, 33);
  root = insertnode(root, 13);
  root = insertnode(root, 53);
  root = insertnode(root, 9);
  root = insertnode(root, 21);
  root = insertnode(root, 61);
  root = insertnode(root, 8);
  root = insertnode(root, 11);
  printTree(root, "", true);
  root = delnode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);
}
// https://www.programiz.com/dsa/avl-tree
